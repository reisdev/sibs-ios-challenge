//
//  FavoriteStorageService.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#if __cplusplus

#ifndef FavoriteStorageService_h
#define FavoriteStorageService_h

#include <sqlite3.h>
#include <string>

namespace Storage {
    class FavoriteStorageService {
        private:
            std::string databasePath;
            sqlite3* database;

            void setup();

        public:
            FavoriteStorageService(std::string databasePath);

            std::vector<std::string> getAllFavorites();
            bool saveFavorite(std::string id);
            bool removeFavorite(std::string id);
            bool isFavorite(std::string id);
            bool removeAllFavorites();
    };
}

#endif /* FavoriteStorageService_h */
#endif
