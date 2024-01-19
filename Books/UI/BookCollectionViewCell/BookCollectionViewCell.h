//
//  BookCollectionViewCell.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import <UIKit/UIKit.h>
#import "BookModel.h"

@interface BookCollectionViewCell : UICollectionViewCell {

    IBOutlet UIImageView* imageView;
    IBOutlet UILabel* titleLabel;
}

- (instancetype)setupWithBookModel:(const BookModel *) bookModel;

@end
