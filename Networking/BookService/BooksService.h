//
//  BooksService.hpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#ifndef BOOKS_SERVICE_h
#define BOOKS_SERVICE_h

#import "NetworkProvider.h"
#import "Book.h"

class BooksService {
    private:
        NetworkProvider * provider;

    public:

    BooksService(NetworkProvider * provider);

    vector<Domain::Book> fetchList(string query, int maxResults, int startIndex);
};

#endif /* BooksService_hpp */
