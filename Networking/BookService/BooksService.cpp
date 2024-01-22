//
//  BooksService.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#include <string>
#include <vector>

#include "BookListingResponse.h"
#include "BooksService.h"

using namespace Networking;

BooksService::BooksService(NetworkProvider* provider) {
    this->provider = provider;
}

BookListingResponse* BooksService::fetchList(std::string query, int maxResults, int startIndex) {
    std::string queryString = "?";

    if(!query.empty()) {
        queryString += "&q=" + query;
    }

    if(maxResults) {
        queryString += "&maxResults=" + std::to_string(maxResults);
    }

    if(startIndex) {
        queryString += "&startIndex=" + std::to_string(startIndex);
    }

    std::string response = this->provider->fetch(queryString);

    BookListingResponse* result = new BookListingResponse;
    parser.parse(response, *result);

    return result;
}

#endif
