//
//  BooksListViewController.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import <UIKit/UIKit.h>

@interface BooksListViewController : UIViewController<UICollectionViewDelegate, UICollectionViewDataSource> {
    IBOutlet UICollectionView *collectionView;
}
@end

