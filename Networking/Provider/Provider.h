//
//  Provider.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#if __cplusplus

#ifndef Provider_h
#define Provider_h

#include <string>

namespace Networking {
    class Provider {
        public:
            virtual std::string fetch(std::string path);
    };
}

#endif /* Provider_h */
#endif
