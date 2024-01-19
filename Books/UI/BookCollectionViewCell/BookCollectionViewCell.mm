//
//  BookCollectionViewCell.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#import <UIKit/UIKit.h>
#import "BookCollectionViewCell.h"
#import "BookModel.h"

@interface BookCollectionViewCell ()

@end

@implementation BookCollectionViewCell

- (instancetype)setupWithBookModel:(const BookModel *)bookModel {
    titleLabel.text = bookModel.title;
    

    return self;
}

+ (NSString *)reuseIdentifier {
    return @"BookCollectionViewCell";
}

@end
