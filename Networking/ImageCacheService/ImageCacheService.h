//
//  CacheService.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#ifndef CacheService_h
#define CacheService_h

#import <string>
#include "../Networking.h"

using namespace Networking;

namespace Networking {
    class ImageCacheService {
        private:
            NetworkProvider* provider;
            std::map<std::string, std::string> cache;
        public:
            ImageCacheService(NetworkProvider*);

        void setValue(std::string value, std::string forKey);
        std::string getValue(std::string forKey);
    };
}
#endif /* CacheService_h */
