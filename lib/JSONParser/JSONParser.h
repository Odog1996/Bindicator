#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
//#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "BinDayInfo.h"

//using json = nlohmann::json;

typedef std::vector<BinDayInfo> BinDays;

class JSONParser{
    public:
        JSONParser(std::string JSONStr);
        BinDays getBinDays();
    private:
        BinDayInfo getBinDay(std::string bin);
        rapidjson::Document document;
};

#endif