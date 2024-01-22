//
//  BookServiceWrapper.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 20/01/24.
//

#import <Foundation/Foundation.h>
#import "BookServiceWrapper.h"
#import "Books/Networking/Models/BookListingResponseWrapper.h"
#import "Networking/BookService/BooksService.h"

@interface BookServiceWrapper () {
    Networking::BooksService* service;
}
@end

@implementation BookServiceWrapper

-(instancetype)init {
    self = [BookServiceWrapper alloc];

    if(!self) {
        return nil;
    }

    Networking::NetworkProvider* provider = new Networking::NetworkProvider("https://www.googleapis.com/books/v1/volumes/");
    self->service = new Networking::BooksService(provider);
    return self;
}

- (BookListingResponseWrapper *)fetchListingWithQuery:(NSString*)query limit:(int)limit offset:(unsigned long)offset {
    long pointer = service->fetchList([query UTF8String], limit,(int) offset)->pointer();
    return [[BookListingResponseWrapper alloc] initWithPointer: pointer];
}

@end
