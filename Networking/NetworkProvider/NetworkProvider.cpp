//
//  NetworkProvider.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#include "NetworkProvider.h"
#include "cURLpp.hpp"
#include "Easy.hpp"
#include "Options.hpp"
#include <string>

using namespace curlpp::Options;

NetworkProvider::NetworkProvider(std::string baseURL) {
    this->baseURL = baseURL;
}

template<class T>
T NetworkProvider::fetch(std::string path) {
    curlpp::Cleanup cleanup;

    curlpp::Easy request;

    curlpp::Options::Url url = curlpp::Options::Url(baseURL + path);

    request.setOpt(url);

    request.perform();
}

