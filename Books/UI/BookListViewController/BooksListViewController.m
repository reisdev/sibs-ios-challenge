//
//  BoostListViewController.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import "UIKit/UIKit.h"

#import "Books/Networking/Service/Book/BookServiceWrapper.h"
#import "Books/Networking/Models/BookListingResponseWrapper.h"
#import "Books/Networking/Service/ImageCache/ImageCacheServiceWrapper.h"
#import "Books/Storage/Favorites/FavoriteStorageServiceWrapper.h"

#import "BooksListViewController.h"
#import "BookCollectionViewCell.h"
#import "../BookDetailViewController/BookDetailViewController.h"

@interface BooksListViewController () {
    NSArray<BookModel*>* items;
    bool isListingFavorites;
}

@property (nonatomic) BookServiceWrapper* service;

@end

@implementation BooksListViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    _service = [[BookServiceWrapper alloc] init];
    items = [[NSArray alloc] init];

    [collectionView registerClass:[BookCollectionViewCell class]
       forCellWithReuseIdentifier:BookCollectionViewCell.reuseIdentifier];
    [collectionView registerNib: [UINib nibWithNibName:@"BookCollectionViewCell" bundle:nil] forCellWithReuseIdentifier:BookCollectionViewCell.reuseIdentifier];

    collectionView.delegate = self;
    collectionView.dataSource = self;

    [self setupSwipeDetectors];

    [self fetchItems];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    BookDetailViewController* controller = (BookDetailViewController*) segue.destinationViewController;

    BookModel* model = (BookModel *) sender;

    if(!controller || !model) {
        return;
    }

    controller.model = model;
}

- (void)setupSwipeDetectors {
    UISwipeGestureRecognizer *swipeLeft = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipedLeft:)];
    [swipeLeft setDirection:UISwipeGestureRecognizerDirectionLeft ];
    [self.view addGestureRecognizer:swipeLeft];

    UISwipeGestureRecognizer *swipeRight = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipedRight:)];
    [swipeRight setDirection:UISwipeGestureRecognizerDirectionRight ];
    [self.view addGestureRecognizer:swipeRight];
}

- (void)swipedLeft:(id)sender {
    if(self->segmentedControl.selectedSegmentIndex == 0) {
        [self->segmentedControl setSelectedSegmentIndex: 1];
        [self didTapSegmentedControl:self->segmentedControl];
    }
}

- (void)swipedRight:(id)sender {
    if(self->segmentedControl.selectedSegmentIndex == 1) {
        [self->segmentedControl setSelectedSegmentIndex: 0];
        [self didTapSegmentedControl:self->segmentedControl];
    }
}

- (void)fetchItems {
    isListingFavorites = false;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        BookListingResponseWrapper* response = [self->_service fetchListingWithQuery:@"ios"
                                                                               limit:10
                                                                              offset:self->items.count];
        [self updateItemsWith:[response getItems]];
    });
}

- (void)fetchFavoriteItems {
    isListingFavorites = true;
    NSArray<NSString*>* favorites = [[FavoriteStorageServiceWrapper shared] getAllFavorites];

    NSString* query = [favorites componentsJoinedByString: @"|"];

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        BookListingResponseWrapper* response = [self->_service fetchListingWithQuery: query
                                                                               limit: (int) favorites.count
                                                                              offset: 0];

        [self updateItemsWith:[response getItems]];
    });
}

- (void) updateItemsWith:(NSArray<BookModel *>*)items {
    self->items = [self->items arrayByAddingObjectsFromArray: items];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self->collectionView reloadData];
    });
}

- (IBAction)didTapSegmentedControl:(id)sender {
    UISegmentedControl* segmentedControl = (UISegmentedControl*) sender;

    NSInteger selected = segmentedControl.selectedSegmentIndex;

    items = [[NSArray alloc] init];

    switch(selected) {
        case 1:
            [self fetchFavoriteItems];
            break;
        default:
            [self fetchItems];
    }
}

- (nonnull __kindof UICollectionViewCell *)collectionView:(nonnull UICollectionView *)collectionView cellForItemAtIndexPath:(nonnull NSIndexPath *)indexPath {

    BookCollectionViewCell* cell = [collectionView dequeueReusableCellWithReuseIdentifier:BookCollectionViewCell.reuseIdentifier forIndexPath:indexPath];

    BookModel* model = items[indexPath.row];

    [cell setupWithBookModel:model];
    [cell toggleLoading];

    [ImageCacheServiceWrapper.shared fetchImageWithUrl:[model getThumbnail:smallThumbnail]
                                            completion: ^(UIImage* image) {
        [cell setupImageWith:image];
        [cell toggleLoading];
    }];

    return cell;
}

- (NSInteger)collectionView:(nonnull UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return items.count;
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {

    // Calculate ideal book cover scale
    CGFloat width = (collectionView.contentSize.width/2.4);
    CGFloat height = width * 1.6;

    return CGSizeMake(width, height);
}

-(void)collectionView:(UICollectionView *)collectionView willDisplayCell:(nonnull UICollectionViewCell *)cell forItemAtIndexPath:(nonnull NSIndexPath *)indexPath {
    if(indexPath.row == items.count-1 && !isListingFavorites) {
        [self fetchItems];
    }
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    BookModel* item = items[indexPath.row];

    [self performSegueWithIdentifier:@"BookDetail" sender: item];
}

@end

