//
//  BookService.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#ifndef BookService_h
#define BookService_h

#import "Books/Networking/Models/BookListingResponseWrapper.h"
#import "BookServiceWrapper.h"

@interface BookServiceWrapper: NSObject

- (instancetype) init;
- (BookListingResponseWrapper *)fetchListingWithQuery:(NSString*)query limit:(int)limit offset:(unsigned long)offset;

@end

#endif /* BookService_h */
