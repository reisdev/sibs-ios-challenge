//
//  BookModel.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 19/01/24.
//

#import <Foundation/Foundation.h>

typedef enum {
    small,
    regular
} Thumbnail;

@interface BookModel: NSObject


- (NSString*)title;
- (NSString*)description;
- (NSString*)authors;
- (NSString*)getThumbnail:(Thumbnail)size;
@end
