#ifndef HTMLPARSER
#define HTMLPARSER

#include <string>
#include <iostream>
#include "BinDayInfo.h"

typedef std::vector<BinDayInfo> BinDays;

class HTMLParser{
public:
    HTMLParser(std::string webpage);
    BinDays getBinDays();
private:
    BinDayInfo getBinDay(std::string bin);
    std::string parseInfo(int location, std::string info, std::string end);
    int convertMonth(std::string month);
    int getYear(int collectionMonth);
    std::string webpage;
};

#endif 