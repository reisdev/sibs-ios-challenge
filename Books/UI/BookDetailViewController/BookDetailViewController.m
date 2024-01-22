//
//  BookDetailViewController.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#import <Foundation/Foundation.h>

#import "Books/Networking/Service/ImageCache/ImageCacheServiceWrapper.h"
#import "Books/Storage/Favorites/FavoriteStorageServiceWrapper.h"
#import "BookDetailViewController.h"

@interface BookDetailViewController()

@property (nonatomic) IBOutlet UIImageView* imageView;
@property (nonatomic) IBOutlet UILabel* titleLabel;
@property (nonatomic) IBOutlet UILabel* authorsLabel;
@property (nonatomic) IBOutlet UILabel* descriptionLabel;
@property (nonatomic) IBOutlet UIButton* buyNowButton;
@property (atomic) bool isFavorite;

@end

@implementation BookDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self setup];
}

- (void)setup {
    self.navigationItem.title = book.title;
    self.titleLabel.text = book.title;
    self.authorsLabel.text = book.authors;
    self.descriptionLabel.text = book.bookDescription;

    if(book.buyLink) {
        [_buyNowButton setHidden: false];
    }

    self->_imageView.layer.cornerRadius = 8.0;
    self->_imageView.layer.masksToBounds = true;

    [ImageCacheServiceWrapper.shared fetchImageWithUrl: [book getThumbnail:regularThumbnail] completion: ^(UIImage * image) {
        self->_imageView.image = image;
    }];

    self.isFavorite = [FavoriteStorageServiceWrapper.shared getFavoriteWithId: book.id];

    if(self.isFavorite) {
        self.navigationItem.rightBarButtonItem.image = [UIImage systemImageNamed: @("heart.fill")];
    }
}

- (void)setModel:(BookModel*)model {
    self->book = model;
};

- (IBAction)didTapBuyNow:(id)sender {
    if(!book.buyLink) {
        return;
    }

    [[UIApplication sharedApplication] openURL: book.buyLink 
                                       options:@{}
                             completionHandler: ^(BOOL success){}];
}

- (IBAction)didTapFavorite:(id)sender {

    UIBarButtonItem* rightBarButtonItem = sender;

    if(!rightBarButtonItem) return;

    if(self.isFavorite) {
        if([FavoriteStorageServiceWrapper.shared removeFavoriteWithId:book.id]) {
            self.isFavorite = false;
            rightBarButtonItem.image = [UIImage systemImageNamed: @("heart")];
        }
    } else {
        if ([FavoriteStorageServiceWrapper.shared saveFavoriteWithId:book.id]) {
            self.isFavorite = true;
            rightBarButtonItem.image = [UIImage systemImageNamed: @("heart.fill")];
        }
    }

    [rightBarButtonItem setBackgroundImage:nil forState:UIControlStateNormal barMetrics: UIBarMetricsDefault];
}

@end
