//
//  NetworkProvider.hpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#ifndef NETWORK_PROVIDER_h
#define NETWORK_PROVIDER_h

#include <string>

using namespace std;

class NetworkProvider {

    private:
        string baseURL;

    public:
        NetworkProvider(string baseURL);
    
        template<class T>
        T fetch(string path);
};

#endif  /* NetworkProvider_hpp */
