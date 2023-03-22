#ifndef COUNCILINFO_H
#define COUNCILINFO_H

#include <string>

enum class AccessType{
    GET,
    POST,
};

class CouncilInfo{
public:
    CouncilInfo();
    std::string getBinDayURL() const;

private:
    AccessType access;
    std::string URL;
};

#endif