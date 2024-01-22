//
//  NetworkProvider.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#include <string>
#include "curlpp/cURLpp.hpp"
#include "curlpp/Easy.hpp"
#include "curlpp/Options.hpp"
#include "NetworkProvider.h"

using namespace Networking;
using namespace curlpp::Options;

NetworkProvider::NetworkProvider(std::string baseURL) {
    this->baseURL = baseURL;
}

std::string NetworkProvider::fetch(std::string path) {
    curlpp::Cleanup cleanup;

    curlpp::Easy request;

    request.setOpt(Url(baseURL + path));

    std::ostringstream response;
    request.setOpt(new curlpp::options::WriteStream(&response));

    request.perform();

    return response.str();
}

#endif
