//
//  BooksService.hpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#ifndef BOOKS_SERVICE_h
#define BOOKS_SERVICE_h

#include "Networking/Provider/NetworkProvider.h"
#include "Networking/Models/BookListingResponse.h"
#include "Domain/Book.h"
#include "Domain/JSONParser/JSONParser.h"

namespace Networking {
    class BooksService {
        private:
            NetworkProvider* provider;
            JSONParser parser;

        public:

        BooksService(NetworkProvider* provider);

        BookListingResponse* fetchList(std::string query, int maxResults, int startIndex);
    };
}

#endif /* BooksService_hpp */
#endif
