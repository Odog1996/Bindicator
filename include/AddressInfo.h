#ifndef ADDRESSINFO_H
#define ADDRESSINFO_H

#include <string>

class AddressInfo{
public:
    AddressInfo();
    std::string getUPRN() const;

private:
    std::string uprn;
};

#endif