#include "NextBinDay.h"

// Assumptions:
// The council never shows a bin day in the past.

BinColour NextBinDay::getBinColour(const BinDays& binDays){
    // 1. Find out todays date and time
    time_t currentTime = time(0);
    tm* localTime = localtime(&currentTime);
    
    // 2. Find out which day is next 
    const BinDayInfo* nextBinDay = &binDays.at(0);
    for(auto& binDay : binDays)
    {
        if(binDay.getBinDate() < nextBinDay->getBinDate()) nextBinDay = &binDay;       
    }

    return nextBinDay->getBinColour();

    // What are the situtations

    // Both bin days are in this month.
    // Both bin days are in next month.
    // One bin day is in either.
}