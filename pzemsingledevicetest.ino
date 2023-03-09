#include <PZEM004Tv30.h>

#define pzemRX 16
#define pzemTX 17

#define pzemSerial Serial2
#define pzemTotal 1

PZEM004Tv30 pzems[pzemTotal];

void setup(){
  Serial.begin(115200);

  for(int i = 0; i < pzemTotal; i++){
    pzems[i] = PZEM004Tv30(pzemSerial, pzemRX, pzemTX, 0xF8);
  }
}

void loop() {
  
  for(int i = 0; i < pzemTotal; i++){ 
    // Print out the measured values from each PZEM module
        Serial.print("PZEM ");
        Serial.print(i);
        Serial.print(" - Address:");
        Serial.println(pzems[i].getAddress(), HEX);
        Serial.println("===================");



        // Read the data from the sensor
        float voltage = pzems[i].voltage();
        float current = pzems[i].current();
        float power = pzems[i].power();
        float energy = pzems[i].energy();
        float frequency = pzems[i].frequency();
        float pf = pzems[i].pf();


        // Check if the data is valid
        if(isnan(voltage)){
            Serial.println("Error reading voltage");
        } else if (isnan(current)) {
            Serial.println("Error reading current");
        } else if (isnan(power)) {
            Serial.println("Error reading power");
        } else if (isnan(energy)) {
            Serial.println("Error reading energy");
        } else if (isnan(frequency)) {
            Serial.println("Error reading frequency");
        } else if (isnan(pf)) {
            Serial.println("Error reading power factor");
        } else {
            // Print the values to the Serial console
            Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
            Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
            Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
            Serial.print("Energy: ");       Serial.print(energy,3);     Serial.println("kWh");
            Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
            Serial.print("PF: ");           Serial.println(pf);

        }

        Serial.println("-------------------");
        Serial.println();
    }

    Serial.println();
    delay(2000);
}
