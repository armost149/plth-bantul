#include <PZEM004Tv30.h>

PZEM004Tv30 pzem(&Serial2, 0x06);

void setup() {
  Serial.begin(115200);
}
 
void loop() {
pzem.resetEnergy();
}
