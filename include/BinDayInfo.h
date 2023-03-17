#ifndef BINDAYINFO_H
#define BINDAYINFO_H

#include <ctime>
#include <vector>

enum class BinColour {Green, Blue};

struct BinDate{
    BinDate(int mday, int month, int year) : mday(mday), month(month), year(year){}
    int	month;
    int	year;
    int mday;
};

inline bool operator <(const BinDate& lhs, const BinDate& rhs)
{
    if(lhs.year < rhs.year) return true;
    if(lhs.year == rhs.year)
    {
        if(lhs.month < rhs.month) return true;
        if((lhs.month == rhs.month) && (lhs.mday == rhs.mday)) return true;
        return false;
    }
    return false;
}

class BinDayInfo{
public:
    BinDayInfo(BinColour colour, BinDate date);
    BinColour getBinColour() const;
    
    BinDate getBinDate() const;
private:
    BinColour binColour;
    BinDate binDate;
};


#endif