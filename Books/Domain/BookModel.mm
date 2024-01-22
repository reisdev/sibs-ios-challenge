//
//  BookModel.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 19/01/24.
//

#import <Foundation/Foundation.h>
#import "Domain/Book.h"
#import "BookModel.h"

@interface BookModel () {
    Domain::Book* book;
}
@end

@implementation BookModel

- (instancetype)initWithPointer:(long)pointer {
    self->book = (Domain::Book*) pointer;
    return self;
}

+ (BookModel*) mock {

    Domain::Book* book = new Domain::Book();

    Domain::VolumeInfo* volumeInfo = new Domain::VolumeInfo();
    volumeInfo->title = "Livro de teste";
    book->id = "test";
    book->volumeInfo = volumeInfo;

    BookModel* result = [BookModel alloc];
    result->book = book;

    return result;
}

- (NSString*) id {
    return [NSString stringWithUTF8String: book->id.c_str()];
}

- (NSString*) title {
    if(!book) { return @""; }

    return [NSString stringWithUTF8String: book->volumeInfo->title.c_str()];
}

- (NSString*) bookDescription {
    return [NSString stringWithUTF8String: book->volumeInfo->description.c_str()];
}

- (NSString*) authors {
    NSString * authors = @("");
    for(int i = 0; i < book->volumeInfo->authors.size(); i++) {
        if(i > 0) {
            authors = [authors stringByAppendingString: @", "];
        }
        authors = [authors stringByAppendingString: [NSString stringWithUTF8String: book->volumeInfo->authors[i].c_str()]];
    }

    return authors;
}

- (NSString *)getThumbnail:(Thumbnail)size {
    switch (size) {
        case smallThumbnail:
            return [NSString stringWithUTF8String: book->volumeInfo->imageLinks->smallThumbnail.c_str()];
        default:
            return [NSString stringWithUTF8String: book->volumeInfo->imageLinks->thumbnail.c_str()];
    }
}

- (NSURL*)buyLink {
    if(!book->saleInfo->buyLink.has_value()) {
        return nil;
    }

    return [NSURL URLWithString: @(book->saleInfo->buyLink.value().c_str())];
}

@end
