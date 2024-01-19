//
//  BoostListViewController.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import "BooksListViewController.h"
#import "BookCollectionViewCell.h"
#import "UIKit/UIKit.h"

@interface BooksListViewController ()

@end

@implementation BooksListViewController

NSString * _Nonnull cellReuseIdentifier = @"cell";

- (void)viewDidLoad {
    [super viewDidLoad];

    [collectionView registerClass:[BookCollectionViewCell class]
       forCellWithReuseIdentifier:cellReuseIdentifier];

    collectionView.delegate = self;
    collectionView.dataSource = self;
}

- (nonnull __kindof UICollectionViewCell *)collectionView:(nonnull UICollectionView *)collectionView cellForItemAtIndexPath:(nonnull NSIndexPath *)indexPath {

    UICollectionViewCell* cell = [collectionView dequeueReusableCellWithReuseIdentifier:cellReuseIdentifier
                                                                           forIndexPath:indexPath];

    return cell;
}

- (NSInteger)collectionView:(nonnull UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return 1;
}

@end

