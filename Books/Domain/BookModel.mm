//
//  BookModel.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 19/01/24.
//

#import <Foundation/Foundation.h>
#import "BookModel.h"
#import "Book.h"

@interface BookModel () {
    Domain::Book book;
}

@end

@implementation BookModel

- (NSString*) title {
    return @(book.volumeInfo.title.c_str());
}
- (NSString*) description {
    return @(book.volumeInfo.description.c_str());
}

- (NSString*) authors {
    NSString * authors;
    for(int i = 0; i < book.volumeInfo.authors.size(); i++) {
        if(i > 0) {
            authors = [authors stringByAppendingString: @", "];
        }
        authors = [authors stringByAppendingString: @(book.volumeInfo.authors[i].c_str())];
    }

    return authors;
}

- (NSString *)getThumbnail:(Thumbnail)size {
    switch (size) {
        case small:
            return @(book.imageLinks.smallThumbnail.c_str());
        case regular:
            return @(book.imageLinks.thumbnail.c_str());
    }
}

@end
