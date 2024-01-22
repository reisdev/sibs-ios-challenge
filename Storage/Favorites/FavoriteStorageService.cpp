//
//  FavoriteStorageService.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 21/01/24.
//

#include "FavoriteStorageService.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <vector>

using namespace Storage;

FavoriteStorageService::FavoriteStorageService(std::string databasePath) {
    this->databasePath = databasePath;
    setup();
}

void FavoriteStorageService::setup() {
    std::fstream databaseFile;

    databaseFile.open(databasePath, std::fstream::in);

    if(!databaseFile) {
        databaseFile.open(databasePath, std::fstream::in | std::fstream::out | std::fstream::app);
        databaseFile << "";

        sqlite3_open(databasePath.c_str(), &database);

        char* messageError;

        std::string query("\
        CREATE TABLE `FAVORITE`( \
            ID INTEGER PRIMARY KEY AUTOINCREMENT,     \
            BOOK_ID            TEXT UNIQUE NOT NULL);   \
        ");

        sqlite3_exec(database, query.c_str(), NULL, 0, &messageError);
        sqlite3_close(database);
    }
}

bool FavoriteStorageService::saveFavorite(std::string id) {
    sqlite3_open(databasePath.c_str(), &database);

    std::string query("INSERT INTO FAVORITE (BOOK_ID) VALUES (?);");

    sqlite3_stmt* stmt;

    int result_code = sqlite3_prepare_v3(database, query.c_str(), (int) query.length(), -1, &stmt, NULL);

    if(result_code != SQLITE_OK) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return false;
    }

    sqlite3_bind_text(stmt, 1, id.c_str(),(int) id.length(), SQLITE_STATIC);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return false;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(database);

    return true;
}

std::vector<std::string> FavoriteStorageService::getAllFavorites() {
    sqlite3_open(databasePath.c_str(), &database);

    sqlite3_stmt* stmt;

    std::string query("SELECT BOOK_ID FROM FAVORITE");

    int result_code = sqlite3_prepare_v3(database, query.c_str(), (int) query.length(), -1, &stmt, NULL);

    if(result_code != SQLITE_OK) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return {};
    }

    std::vector<std::string> results = {};

    while(sqlite3_step(stmt) == SQLITE_ROW) {
        std::string id = (const char *)sqlite3_column_text(stmt, 0);
        results.push_back(id);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(database);

    return results;
}

bool FavoriteStorageService::isFavorite(std::string id) {
    sqlite3_open(databasePath.c_str(), &database);

    sqlite3_stmt* stmt;

    std::string query("SELECT BOOK_ID FROM FAVORITE WHERE BOOK_ID=?;");

    int result_code = sqlite3_prepare_v3(database, query.c_str(), (int) query.length(), -1, &stmt, NULL);;

    if(result_code != SQLITE_OK) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return false;
    }

    sqlite3_bind_text(stmt, 1, id.c_str(),(int) id.length(), SQLITE_STATIC);

    if(sqlite3_step(stmt) == SQLITE_ROW) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return true;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(database);

    return false;
}

bool FavoriteStorageService::removeFavorite(std::string id) {
    sqlite3_open(databasePath.c_str(), &database);

    sqlite3_stmt* stmt;

    std::string query("DELETE FROM FAVORITE WHERE BOOK_ID = ?;");

    sqlite3_prepare(database, query.c_str(),(int) query.length(), &stmt, NULL);

    sqlite3_bind_text(stmt, 1, id.c_str(), (int) id.length(), SQLITE_STATIC);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return false;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(database);
    return true;
}

bool FavoriteStorageService::removeAllFavorites() {
    sqlite3_open(databasePath.c_str(), &database);

    sqlite3_stmt* stmt;

    std::string query("DELETE FROM FAVORITE WHERE 1");

    sqlite3_prepare(database, query.c_str(),(int) query.length(), &stmt, NULL);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return false;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(database);
    return true;
}
