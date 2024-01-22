//
//  JSONParser.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#include <string>
#include "JSONParser.h"

void JSONParser::parse(const std::string &jsonString, Domain::Book& book) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    book.id = jsonData["id"].asString();

    book.saleInfo = new Domain::SaleInfo;
    parse(jsonData["saleInfo"].toStyledString(), *book.saleInfo);

    book.volumeInfo = new Domain::VolumeInfo;
    parse(jsonData["volumeInfo"].toStyledString(), *book.volumeInfo);
}

void JSONParser::parse(const std::string &jsonString, Domain::SaleInfo& info) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);
    if(jsonData.isMember("buyLink")) {
        info.buyLink = jsonData["buyLink"].asString();
    }
}

void JSONParser::parse(const std::string &jsonString, Domain::VolumeInfo& info) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    info.title = jsonData["title"].asString();
    info.description = jsonData["description"].asString();

    if(jsonData.isMember("imageLinks")) {

        info.imageLinks = new Domain::ImageLinks;
        parse(jsonData["imageLinks"].toStyledString(), *info.imageLinks);
    }

    if(jsonData.isMember("authors")) {
        const Json::Value authors = jsonData["authors"];

        for(int i = 0; i < authors.size(); i++) {
            info.authors.push_back(authors[i].asString());
        }
    }
}

void JSONParser::parse(const std::string &jsonString, Domain::ImageLinks& imageLinks) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    imageLinks.smallThumbnail = jsonData["smallThumbnail"].asString();
    imageLinks.thumbnail = jsonData["thumbnail"].asString();
}

void JSONParser::parse(const std::string &jsonString, Networking::BookListingResponse& response) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    if(jsonData.isMember("kind")) {
        response.kind = jsonData["kind"].asString();
    }
    if(jsonData.isMember("totalItems")) {
        response.totalItems = jsonData["totalItems"].asInt();
    }

    if(jsonData.isMember("items")) {

        Json::Value items = jsonData["items"];

        for(int i = 0; i < items.size(); i++) {
            Domain::Book* item = new Domain::Book;
            parse(items.get(i, Json::Value()).toStyledString(), *item);
            response.items.push_back(item);
        }
    }
}

#endif
