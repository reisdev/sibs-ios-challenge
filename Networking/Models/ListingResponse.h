//
//  ListingResponse.hpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 19/01/24.
//
#if __cplusplus
#ifndef ListingResponse_h
#define ListingResponse_h

#include <string>
#include <vector>

namespace Networking {

    template<class T>
    class ListingResponse {
        public:
            std::string kind;
            int totalItems;
            std::vector<T> items;
    };
}

#endif /* ListingResponse_h */
#endif
