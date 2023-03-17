#include "HTMLParser.h"

HTMLParser::HTMLParser(std::string HTML) : webpage(HTML)
{

}

BinDays HTMLParser::getBinDays(){
    // Hacky but fast.
    BinDays binDays;
    binDays.push_back(getBinDay("Blue Bin"));
    binDays.push_back(getBinDay("Green Bin"));
    return binDays;
}

BinDayInfo HTMLParser::getBinDay(std::string bin)
{
    std::string dayString = "<p class=\"bin-collection-tasks__day\">";
    std::string dateString ="<p class=\"bin-collection-tasks__date\">";
    std::string dataEnd = "</p>";
    size_t binColourlocation = webpage.find(bin);
    if(binColourlocation != std::string::npos)
    {
        std::string dayStr = parseInfo(binColourlocation, dayString, dataEnd);
        std::string dateString = parseInfo(binColourlocation, dateString, dataEnd);
        size_t pos = dateString.find(" ");
        int day = std::stoi(dateString.substr(0, pos));
        int month = convertMonth(dateString.substr(pos + 1, (dateString.size() - (pos + 1))));
        int year = getYear(month);
        BinDate date = BinDate(day, month, year);
        if(bin == "Blue Bin") return BinDayInfo(BinColour::Blue, date);
        return BinDayInfo(BinColour::Green, date);
    }
}

std::string HTMLParser::parseInfo(int location, std::string info, std::string end)
{
    size_t textLocation = webpage.find(info, location);
    if(textLocation != std::string::npos)
    {
        size_t endLocation = webpage.find(end, textLocation);
        if(endLocation != std::string::npos)
        {
            int dataStart = textLocation + info.size();
            return webpage.substr(dataStart, endLocation - dataStart);
        }
    }
    return "";
}

int HTMLParser::convertMonth(std::string month)
{
    if(month == "January") return 1;
    if(month == "February") return 2;
    if(month == "March") return 3;
    if(month == "April") return 4;
    if(month == "May") return 5;
    if(month == "June") return 6;
    if(month == "July") return 7;
    if(month == "August") return 8;
    if(month == "September") return 9;
    if(month == "October") return 10;
    if(month == "November") return 11;
    if(month == "December") return 12;
}

int HTMLParser::getYear(int collectionMonth)
{
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    if(collectionMonth < pTInfo->tm_mon)
        return (1900 + pTInfo->tm_year + 1);
    return 1900 + pTInfo->tm_year;
}