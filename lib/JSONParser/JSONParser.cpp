#include "JSONParser.h"

JSONParser::JSONParser(std::string JSON){
    document.Parse(JSON.c_str());
}

BinDays JSONParser::getBinDays()
{
    BinDays binDays;
    binDays.push_back(getBinDay("Blue Bin"));
    binDays.push_back(getBinDay("Green Bin"));
    return binDays;
}

BinDayInfo JSONParser::getBinDay(std::string bin)
{
    BinDate date = BinDate(01,01,01);
    rapidjson::Value& s = document["NextCollection"];
    int day;
    int month;
    int year;
    date = BinDate(day,month,year);

}