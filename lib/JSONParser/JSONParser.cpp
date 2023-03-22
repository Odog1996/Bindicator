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
    rapidjson::Value& body = document["body"];
    for(int i = 0; i < body.Size(); ++i)
    {
        const rapidjson::Value& item = body[i];

        int day;
        int month;
        int year;
        date = BinDate(day,month,year);
        std::string date = item["NextCollection"].GetString();
    }

}

/*
const char *json = "{\"status\": \"OK\", \"body\": [{\"collectionType\": \"Refuse\", \"roundInfo\": \"Thu1\", \"LongDate\": \"Thursday 23 March\", \"notes\": null, \"crew\": \"R3\", \"NextCollection\": \"2023-03-23\"}, {\"collectionType\": \"Recycling\", \"roundInfo\": \"Thu1\", \"LongDate\": \"Thursday 30 March\", \"notes\": null, \"crew\": \"Z3\", \"NextCollection\": \"2023-03-30\"}, {\"collectionType\": \"Garden\", \"roundInfo\": null, \"LongDate\": \"Thursday 23 March\", \"notes\": null, \"crew\": \"V2\", \"NextCollection\": \"2023-03-23\"}, {\"collectionType\": \"Food\", \"roundInfo\": \"Thu1\", \"LongDate\": \"Thursday 23 March\", \"notes\": null, \"crew\": \"K2\", \"NextCollection\": \"2023-03-23\"}]}";

Document doc;
doc.Parse(json);

if (!doc.IsObject() || !doc.HasMember("body"))
{
    std::cerr << "Invalid JSON" << std::endl;
    return 1;
}

const Value &body = doc["body"];
if (!body.IsArray())
{
    std::cerr << "Invalid JSON" << std::endl;
    return 1;
}

for (SizeType i = 0; i < body.Size(); i++)
{
    const Value &item = body[i];
    if (item.IsObject() && item.HasMember("NextCollection"))
    {
        std::cout << "NextCollection: " << item["NextCollection"].GetString() << std::endl;
    }
}
*/