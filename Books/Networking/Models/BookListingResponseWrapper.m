//
//  BookListingResponse.m
//  Books
//
//  Created by Matheus dos Reis de Jesus on 20/01/24.
//

#import <Foundation/Foundation.h>

#import "Networking/Models/BookListingResponse.h"
#import "BookListingResponseWrapper.h"
#import "BookModel.h"

@interface BookListingResponseWrapper () {
    Networking::BookListingResponse* response;
}
@end

@implementation BookListingResponseWrapper

- (instancetype)initWithPointer:(long)pointer {
    self->response = (Networking::BookListingResponse*) pointer;

    return self;
}

- (NSArray<BookModel*>*) getItems {
    NSMutableArray<BookModel*>* items = [[NSMutableArray alloc] init];

    for(unsigned long i = 0; i < response->items.size(); i++) {
        long pointer = response->items[i]->pointer();
        BookModel* item = [[BookModel alloc] initWithPointer:pointer];

        [items addObject: item];
    }

    return items;
}

- (NSString *)getKind {
    return @(self->response->kind.c_str());
}

- (NSNumber *)getTotalItems {
    return [NSNumber numberWithInt: self->response->totalItems];
}

@end
