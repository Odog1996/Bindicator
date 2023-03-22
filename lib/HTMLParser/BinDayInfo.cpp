#include "BinDayInfo.h"

BinDayInfo::BinDayInfo(BinColour colour, BinDate date) : binColour(colour), binDate(date){

}

BinColour BinDayInfo::getBinColour() const{
    return binColour;
}

// Get the day of the month
BinDate BinDayInfo::getBinDate() const{
    return binDate;
}