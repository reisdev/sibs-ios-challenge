//
//  JSONParser.h
//  Books
//
//  Created by Matheus dos Reis de Jesus on 18/01/24.
//

#if defined __cplusplus

#ifndef JSONParser_h
#define JSONParser_h

#include "json.h"
#include "Book.h"
#include "ListingResponse.h"

class JSONParser {

    private:
        Json::Reader reader;

    public:

    template<class T>
    T parse(const std::string &jsonString, T& out);

    void parse(const std::string &jsonString, Domain::Book& book);
    void parse(const std::string &jsonString, Domain::SaleInfo& info);
    void parse(const std::string &jsonString, Domain::VolumeInfo& info);
    void parse(const std::string &jsonString, Domain::ImageLinks& imageLinks);

    template <class T>
    void parse(const std::string &jsonString, Networking::ListingResponse<T>& response);
};

#endif /* JSONParser_h */

#endif
