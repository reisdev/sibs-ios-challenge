//
//  NetworkProvider.hpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#ifndef NETWORK_PROVIDER_h
#define NETWORK_PROVIDER_h

#include <string>
#include "Domain/JSONParser/JSONParser.h"
#include "Networking/Models/BookListingResponse.h"
#include "Domain/Book.h"
#include "Provider.h"

namespace Networking {
    class NetworkProvider {
        private:
            std::string baseURL;

        public:
            NetworkProvider(std::string baseURL);

            std::string fetch(std::string path);
    };
};

#endif  /* NetworkProvider_hpp */
#endif
