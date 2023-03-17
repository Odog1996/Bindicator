#ifndef COUNCILINFO_H
#define COUNCILINFO_H

#include <string>
class CouncilInfo{
public:
    CouncilInfo();
    std::string getBinDayURL() const;

private:
    std::string URL;
};

#endif