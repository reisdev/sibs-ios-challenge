//
//  ImageCacheService.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#if __cplusplus

#include "ImageCacheService.h"

ImageCacheService::ImageCacheService(Networking::NetworkProvider* provider) {
    this->provider = provider;
    this->cache = std::map<std::string, std::string>();
}

std::string ImageCacheService::getValue(std::string key) {
    if(cache.find(key) == cache.end()) {
        std::string value = this->provider->fetch(key);
        cache[key] = value;
        return value;
    }

    return cache[key];
}

#endif
