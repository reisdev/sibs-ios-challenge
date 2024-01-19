//
//  Book.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#ifdef __cplusplus

#ifndef Book_h
#define Book_h

#include <string>
#include <vector>

namespace Domain {
    struct ImageLinks {
        public:
            std::string smallThumbnail;
            std::string thumbnail;
    };

    struct VolumeInfo {
        public:
            std::string title;
            std::vector<std::string> authors;
            std::string description;
    };

    struct SaleInfo {
        public:
            std::optional<std::string> buyLink;
    };

    struct Book {
        public:
            std::string id;
            VolumeInfo volumeInfo;
            ImageLinks imageLinks;
            SaleInfo saleInfo;
    };
}

#endif /* Book_h */

#endif
