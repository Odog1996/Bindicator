

/* Bindicator.
 * 
 * I want to see how hard this would be to do. Cherwill Council has a nice 
 * website which I suspect I can just make a HTTP request to and parse the
 * colours out of the response.
 * 
*/

#ifdef ARDUINO

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

#else

int main(int argc, char **argv)
{
  return 0;
}

#endif

// You quickly see how this didn't take off.

// Tewkesbury URL (GET):
//'https://api-2.tewkesbury.gov.uk/general/rounds/GL20%206EH/nextCollection'

// Cherwell URL (GET) (Note: You need the UPRN):
//''