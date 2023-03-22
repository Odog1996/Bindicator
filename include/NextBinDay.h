#ifndef NEXTBINDAY_H
#define NEXTBINDAY_H

#include "BinDayInfo.h"

typedef std::vector<BinDayInfo> BinDays;

class NextBinDay{
public:
    static BinColour getBinColour(const BinDays& binDays);

private:
    NextBinDay();
};



#endif