//
//  BookCollectionViewCell.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import <UIKit/UIKit.h>
#import "BookModel.h"

@interface BookCollectionViewCell: UICollectionViewCell {
    
}

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;

+ (NSString*) reuseIdentifier;
- (void)setupWithBookModel:(const BookModel *)model;
- (void)setupImageWith:(UIImage*)image;
- (void)toggleLoading;

@end
