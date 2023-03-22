``` mermaid
---
title: Bindicator
---
classDiagram

class AddressInfo{
    - string PostCode
    - string Address
    - string uprn
}

class CouncilInfo{
    - Website
}

class BinDayRequester{
    + BinDayRequester(HTTP)
    + BinDayInfo RequestBinDay(AddressInfo, CouncilInfo)
}

class BinDayInfo{
    - Date BinDay
    - eBinColour Colour
    + eBinColour getBinColour()
    + Date getBinDay()
}

class XMLParser{
    + 
}

BinDayRequester <-- AddressInfo
BinDayRequester <-- CouncilInfo
BinDayRequester <-- BinDayInfo
BinDayRequester *-- XMLParser

```

