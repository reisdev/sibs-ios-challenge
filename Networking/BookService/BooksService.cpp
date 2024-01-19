//
//  BooksService.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#include <string>
#include <vector>

#include "NetworkProvider.h"
#include "BooksService.h"
#include "ListingResponse.h"

using namespace std;

BooksService::BooksService(NetworkProvider* provider) {
    this->provider = provider;
}

vector<Domain::Book> BooksService::fetchList(string query, int maxResults, int startIndex) {

    string queryString = "?";

    if(!query.empty()) {
        queryString += "&q=" + query;
    }

    if(maxResults) {
        queryString += "&maxResults=" + to_string(maxResults);
    }

    if(startIndex) {
        queryString += "&startIndex=" + to_string(startIndex);
    }

    auto response = this->provider->fetch<Networking::ListingResponse<Domain::Book>>(queryString);

    return response.items;
}
