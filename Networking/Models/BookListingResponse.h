//
//  BookListingResponse.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 20/01/24.
//

#if __cplusplus

#ifndef BOOK_LISTING_RESPONSE_H
#define BOOK_LISTING_RESPONSE_H

#include "ListingResponse.h"
#include "Domain/Book.h"

namespace Networking {
    class BookListingResponse: public ListingResponse<Domain::Book> {
    };
};

#endif /* BOOK_LISTING_RESPONSE_H */
#endif
