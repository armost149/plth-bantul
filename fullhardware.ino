#include <PZEM004Tv30.h>

PZEM004Tv30 pzem1(&Serial2, 0x01);
PZEM004Tv30 pzem2(&Serial2, 0x02);
PZEM004Tv30 pzem3(&Serial2, 0x03);
PZEM004Tv30 pzem4(&Serial2, 0x04);
PZEM004Tv30 pzem5(&Serial2, 0x05);
PZEM004Tv30 pzem6(&Serial2, 0x06);

void setup() {
  Serial.begin(115200);
}

void loop() {
pzemUpdate();
}

void pzemUpdate(){   
  float volt1 = pzem1.voltage(); Serial.print("V1 : "); Serial.print(volt1); Serial.println(" V");
  float curr1 = pzem1.current(); Serial.print("I1 :"); Serial.print(curr1); Serial.println(" A");
  float powe1 = pzem1.power(); Serial.print("W1: "); Serial.print(powe1); Serial.println(" W");
  float ener1 = pzem1.energy(); Serial.print("kWh1: "); Serial.print(ener1, 3); Serial.println(" kWh");
  float freq1 = pzem1.frequency(); Serial.print("f1: "); Serial.print(freq1, 1); Serial.println(" Hz");
  float pf1 = pzem1.pf(); Serial.print("PF1: "); Serial.println(pf1); Serial.println();

  float volt2 = pzem2.voltage(); Serial.print("V2: "); Serial.print(volt2); Serial.println(" V");
  float curr2 = pzem2.current(); Serial.print("I2: "); Serial.print(curr2); Serial.println(" A");
  float powe2 = pzem2.power(); Serial.print("W: "); Serial.print(powe2); Serial.println(" W");
  float ener2 = pzem2.energy(); Serial.print("kWh: "); Serial.print(ener2, 3); Serial.println(" kWh");
  float freq2 = pzem2.frequency(); Serial.print("f2: ");Serial.print(freq2, 1); Serial.println(" Hz");
  float pf2 = pzem2.pf(); Serial.print("PF2: "); Serial.println(pf2); Serial.println();

  float volt3 = pzem3.voltage(); Serial.print("V3: "); Serial.print(volt3); Serial.println(" V");
  float curr3 = pzem3.current(); Serial.print("I3: "); Serial.print(curr3); Serial.println(" A");
  float powe3 = pzem3.power(); Serial.print("W3: "); Serial.print(powe3); Serial.println(" W");
  float ener3 = pzem3.energy(); Serial.print("kWh3: ");Serial.print(ener3, 3); Serial.println(" kWh");
  float freq3 = pzem3.frequency(); Serial.print("f3: "); Serial.print(freq3, 1); Serial.println(" Hz");
  float pf3 = pzem3.pf(); Serial.print("PF: ");Serial.println(pf3); Serial.println();

  float volt4 = pzem4.voltage(); Serial.print("V4: "); Serial.print(volt4); Serial.println(" V");
  float curr4 = pzem4.current(); Serial.print("I4: "); Serial.print(curr4); Serial.println(" A");
  float powe4 = pzem4.power(); Serial.print("W4: "); Serial.print(powe4); Serial.println(" W");
  float ener4 = pzem4.energy(); Serial.print("kWh4: "); Serial.print(ener4, 3); Serial.println(" kWh");
  float freq4 = pzem4.frequency(); Serial.print("f4: "); Serial.print(freq4, 1); Serial.println(" Hz");
  float pf4 = pzem4.pf(); Serial.print("PF4: "); Serial.println(pf4); Serial.println();

  float volt5 = pzem5.voltage(); Serial.print("V5: "); Serial.print(volt5); Serial.println(" V");
  float curr5 = pzem5.current(); Serial.print("I5: "); Serial.print(curr5); Serial.println(" A");
  float powe5 = pzem5.power(); Serial.print("W5: "); Serial.print(powe5); Serial.println(" W");
  float ener5 = pzem5.energy(); Serial.print("kWh5: "); Serial.print(ener5, 3); Serial.println(" kWh");
  float freq5 = pzem5.frequency(); Serial.print("f5: "); Serial.print(freq5, 1); Serial.println(" Hz");
  float pf5 = pzem5.pf(); Serial.print("PF5: "); Serial.println(pf5); Serial.println();

  float volt6 = pzem6.voltage(); Serial.print("V6: "); Serial.print(volt6); Serial.println(" V");
  float curr6 = pzem6.current(); Serial.print("I6: "); Serial.print(curr6); Serial.println(" A");
  float powe6 = pzem6.power(); Serial.print("W6: "); Serial.print(powe6); Serial.println(" W");
  float ener6 = pzem6.energy(); Serial.print("kWh6: "); Serial.print(ener6, 3); Serial.println(" kWh");
  float freq6 = pzem6.frequency(); Serial.print("f6: "); Serial.print(freq6, 1); Serial.println(" Hz");
  float pf6 = pzem6.pf(); Serial.print("PF6 :");Serial.println(pf6); Serial.println();

  delay(2000);
}
