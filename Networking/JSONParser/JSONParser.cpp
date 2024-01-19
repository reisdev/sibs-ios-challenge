//
//  JSONParser.cpp
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if defined __cplusplus

#include <string>
#include "JSONParser.h"

void JSONParser::parse(const std::string &jsonString, Domain::Book& book) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    book.id = jsonData["id"].asString();
    parse(jsonData["saleInfo"].asString(), book.saleInfo);
    parse(jsonData["volumeInfo"].asString(), book.volumeInfo);
}

void JSONParser::parse(const std::string &jsonString, Domain::SaleInfo& info) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);
    if(jsonData["buyLink"]) {
        info.buyLink = jsonData["buyLink"].asString();
    }
}

void JSONParser::parse(const std::string &jsonString, Domain::VolumeInfo& info) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    info.title = jsonData["title"].asString();
    info.description = jsonData["description"].asString();

    const Json::Value authors = jsonData["authors"];

    for(int i = 0; i < authors.size(); i++) {
        info.authors.push_back(authors[i].asString());
    }
}

void JSONParser::parse(const std::string &jsonString, Domain::ImageLinks& imageLinks) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    imageLinks.smallThumbnail = jsonData["smallThumbnail"].asString();
    imageLinks.thumbnail = jsonData["thumbnail"].asString();
}

template <class T>
void JSONParser::parse(const std::string &jsonString, Networking::ListingResponse<T>& response) {
    Json::Value jsonData;

    reader.parse(jsonString, jsonData);

    response.kind = jsonData["kind"].asString();
    response.totalItems = jsonData["totalItems"].asInt();

    const Json::Value items = jsonData["items"];

    for(int i = 0; i < items.size(); i++) {
        T item;
        parse(items[i].asString(), item);
        response.items.push_back(item);
    }
}

#endif
