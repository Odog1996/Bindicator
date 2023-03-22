#include <unity.h>
#include <string>
#include "HTMLParser.h"
#include "JSONParser.h"

void setUp(void){

}

void tearDown(void){

}

void test_html_parser_cherwell_webpage(){

    std::string webpage = "<div class=\"widget widget--bin-collection-search\" data-widgetId=\"994\"><div class=\"bin-collection-results\"><p>The address you selected is:  . <a href=\"/info/10/rubbish-and-recycling?changeAddress=true\" class=\"bin-collection-results__reset-link\"><span class=\"visually-hidden\">Not your address? </span>Select a different address</a></p><h2 class=\"bin-collection-results__collection-day\">Your bin collection day is <strong>Friday</strong></h2><div class=\"bin-collection-results__tasks\"><ul class=\"list bin-collection-tasks\"><li class=\"list__item\"><div class=\"boxed\"><img class=\"icon bin-collection-tasks__icon\" src=\"https://forms.cherwell.gov.uk/images/bin-collections/bin-collection-green.svg\" alt=\"green bin collection\"><h3 class=\"bin-collection-tasks__heading\"><span class=\"visually-hidden\">Your next </span>Green Bin<span class=\"visually-hidden\"> collection</span></h3><div class=\"bin-collection-tasks__content\"><p class=\"bin-collection-tasks__day\">Friday</p><p class=\"bin-collection-tasks__date\">17th March</p></div></div></li><li class=\"list__item\"><div class=\"boxed\"><img class=\"icon bin-collection-tasks__icon\" src=\"https://forms.cherwell.gov.uk/images/bin-collections/bin-collection-blue.svg\" alt=\"blue bin collection\"><h3 class=\"bin-collection-tasks__heading\"><span class=\"visually-hidden\">Your next </span>Blue Bin<span class=\"visually-hidden\"> collection</span></h3><div class=\"bin-collection-tasks__content\"><p class=\"bin-collection-tasks__day\">Friday</p><p class=\"bin-collection-tasks__date\">24th March</p></div></div></li></ul></div></div></div>";

    HTMLParser htmlParser = HTMLParser(webpage);
    BinDays days = htmlParser.getBinDays();

    TEST_ASSERT_EQUAL(2, days.size());
    BinDayInfo blueBinDay = days.at(0);
    BinDayInfo brownBinDay = days.at(1);
    TEST_ASSERT_EQUAL(24, blueBinDay.getBinDate().mday);
    TEST_ASSERT_EQUAL(17, brownBinDay.getBinDate().mday);
}

void test_json_parser_tewkesbury_webpage(){
    std::string webpage = "{\"status\": \"OK\", \"body\": [{\"collectionType\": \"Refuse\", \"roundInfo\": \"Thu1\", \"LongDate\": \"Thursday 23 March\", \"notes\": null, \"crew\": \"R3\", \"NextCollection\": \"2023-03-23\"}, {\"collectionType\": \"Recycling\", \"roundInfo\": \"Thu1\", \"LongDate\": \"Thursday 30 March\", \"notes\": null, \"crew\": \"Z3\", \"NextCollection\": \"2023-03-30\"}, {\"collectionType\": \"Garden\", \"roundInfo\": null, \"LongDate\": \"Thursday 23 March\", \"notes\": null, \"crew\": \"V2\", \"NextCollection\": \"2023-03-23\"}, {\"collectionType\": \"Food\", \"roundInfo\": \"Thu1\", \"LongDate\": \"Thursday 23 March\", \"notes\": null, \"crew\": \"K2\", \"NextCollection\": \"2023-03-23\"}]}";

    JSONParser jsonParser = JSONParser(webpage);
    BinDays days = jsonParser.getBinDays();

    TEST_ASSERT_EQUAL(2, days.size());
}



int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_html_parser_cherwell_webpage);
    UNITY_END();
}
