//
//  JSONParser.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if __cplusplus

#ifndef JSONParser_h
#define JSONParser_h

#import <jsoncpp/json.h>
#import "Domain/Book.h"
#import "Networking/Models/BookListingResponse.h"

class JSONParser {

    private:
        Json::Reader reader;

    public:

    void parse(const std::string &jsonString, Domain::Book& book);
    void parse(const std::string &jsonString, Domain::SaleInfo& info);
    void parse(const std::string &jsonString, Domain::VolumeInfo& info);
    void parse(const std::string &jsonString, Domain::ImageLinks& imageLinks);

    void parse(const std::string &jsonString, Networking::BookListingResponse& response);
};

#endif /* JSONParser_h */

#endif
