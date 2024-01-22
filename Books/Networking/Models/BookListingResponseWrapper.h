//
//  BookListingResponseWrapper.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 20/01/24.
//

#ifndef BookListingResponse_h
#define BookListingResponse_h

#import "BookModel.h"

@interface BookListingResponseWrapper: NSObject

-(instancetype)initWithPointer:(long)pointer;

- (NSArray<BookModel*>*) getItems;
- (NSString*) getKind;
- (NSNumber*) getTotalItems;

@end

#endif /* BookListingResponseWrapper_h */
