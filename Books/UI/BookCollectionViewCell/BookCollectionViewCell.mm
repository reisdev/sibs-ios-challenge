//
//  BookCollectionViewCell.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import <UIKit/UIKit.h>
#import "BookCollectionViewCell.h"

@interface BookCollectionViewCell ()

@end

@implementation BookCollectionViewCell

+ (NSString *)reuseIdentifier {
    return @"BookCollectionViewCell";
}

- (void)setupWithBookModel:(const BookModel *)bookModel {
    _titleLabel.text = bookModel.title;
}

- (void)setupImageWith:(UIImage*)image {

    self->_imageView.layer.cornerRadius = 8.0;
    self->_imageView.layer.masksToBounds = true;

    self->_imageView.image = image;
}

- (void)toggleLoading {
    if(self->_activityIndicator.isAnimating) {
        [self->_activityIndicator stopAnimating];
        [self->_activityIndicator setHidden:true];
    } else {
        self->_imageView.image = nil;
        [self->_activityIndicator startAnimating];
        [self->_activityIndicator setHidden:false];
    }
}

@end
