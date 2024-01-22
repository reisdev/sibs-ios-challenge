//
//  BookModel.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 19/01/24.
//

#import <Foundation/Foundation.h>

typedef enum {
    smallThumbnail,
    regularThumbnail,
} Thumbnail;

@interface BookModel: NSObject

- (instancetype)initWithPointer:(long)pointer;

- (NSString*)id;
- (NSString*)title;
- (NSString*)bookDescription;
- (NSString*)authors;
- (NSString*)getThumbnail:(Thumbnail)size;
- (NSURL*)buyLink;

+ (instancetype) mock;

@end
