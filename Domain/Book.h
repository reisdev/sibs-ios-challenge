//
//  Book.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#ifndef Book_h
#define Book_h

#include <string>
#include <vector>

namespace Domain {
    class ImageLinks {
        public:
            std::string smallThumbnail;
            std::string thumbnail;
    };

    class VolumeInfo {
        public:
            std::string title;
            std::vector<std::string> authors;
            std::string description;
            ImageLinks* imageLinks;
    };

    class SaleInfo {
        public:
            std::optional<std::string> buyLink;
    };

    class Book {
        public:
            std::string id;
            VolumeInfo* volumeInfo;
            SaleInfo* saleInfo;

        long pointer() {
            return (long) this;
        }
    };
}

#endif /* Book_h */

#endif
