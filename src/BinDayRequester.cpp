#include "BinDayRequester.h"
/*
BinDays BinDayRequester::requestBinDays(AddressInfo address, CouncilInfo council){
    // No point making the request if we aren't connected to WiFi.
    if(wifi->status() == WL_CONNECTED)
    {
        std::string requestPath = council.getBinDayURL();
        http.begin(client, requestPath.c_str());

        int httpResponseCode = http.GET();
        
        if(httpResponseCode > 0)
        {

        }
        http.end();
    }
    else{
        // Do something. Throw?
    }
}
*/