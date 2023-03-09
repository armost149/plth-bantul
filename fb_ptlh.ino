#include <WiFi.h>
#include <FirebaseESP32.h>
#include <PZEM004Tv30.h>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID " "
#define WIFI_PASSWORD " "
#define API_KEY " "
#define DATABASE_URL " "

String deviceLocation = "PLTH Bayu Baru Bantul";
FirebaseData fbdo;
FirebaseConfig config;
FirebaseAuth auth;
String databasePath;
String fuid;

unsigned long elapsedMillis = 0;
unsigned long updateInterval = 100000;
bool isAuthenticated = false;

float volt1; float curr1; float powe1; float ener1; float freq1; float pf1;
float volt2; float curr2; float powe2; float ener2; float freq2; float pf2;
float volt3; float curr3; float powe3; float ener3; float freq3; float pf3;
float volt4; float curr4; float powe4; float ener4; float freq4; float pf4;
float volt5; float curr5; float powe5; float ener5; float freq5; float pf5;
float volt6; float curr6; float powe6; float ener6; float freq6; float pf6;

FirebaseJson volt1json;FirebaseJson curr1json;FirebaseJson powe1json;FirebaseJson ener1json;FirebaseJson freq1json;FirebaseJson pf1json;
FirebaseJson volt2json;FirebaseJson curr2json;FirebaseJson powe2json;FirebaseJson ener2json;FirebaseJson freq2json;FirebaseJson pf2json;
FirebaseJson volt3json;FirebaseJson curr3json;FirebaseJson powe3json;FirebaseJson ener3json;FirebaseJson freq3json;FirebaseJson pf3json;
FirebaseJson volt4json;FirebaseJson curr4json;FirebaseJson powe4json;FirebaseJson ener4json;FirebaseJson freq4json;FirebaseJson pf4json;
FirebaseJson volt5json;FirebaseJson curr5json;FirebaseJson powe5json;FirebaseJson ener5json;FirebaseJson freq5json;FirebaseJson pf5json;
FirebaseJson volt6json;FirebaseJson curr6json;FirebaseJson powe6json;FirebaseJson ener6json;FirebaseJson freq6json;FirebaseJson pf6json;

void wfInit(){
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
      Serial.print(".");
      delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void fbInit(){
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.reconnectWiFi(true);

  Serial.println("Signing up new user...");

  if (Firebase.signUp(&config, &auth, "", "")){
    isAuthenticated = true;
    Serial.println("Sign up success!");
    
    databasePath = "/" + deviceLocation;
    fuid = auth.token.uid.c_str();
  }
  else{
    isAuthenticated = false;
    Serial.println("Sign up failed");
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
}

void dbInit(){
  volt1 = curr1 = powe1 = ener1 = freq1 = pf1 = 0;
  volt1json.add("name", "Voltage PZEM1"); volt1json.add("value", volt1);
  curr1json.add("name", "Current PZEM1"); curr1json.add("value", curr1);
  powe1json.add("name", "Power PZEM1"); powe1json.add("value", powe1);
  ener1json.add("name", "Energy PZEM1"); ener1json.add("value", ener1);
  freq1json.add("name", "Frequency PZEM1"); freq1json.add("value", freq1);
  pf1json.add("name", "PF PZEM1"); pf1json.add("value", pf1);

  volt2 = curr2 = powe2 = ener2 = freq2 = pf2 = 0;
  volt2json.add("name", "Voltage PZEM1"); volt2json.add("value", volt2);
  curr2json.add("name", "Current PZEM1"); curr2json.add("value", curr2);
  powe2json.add("name", "Power PZEM1"); powe2json.add("value", powe2);
  ener2json.add("name", "Energy PZEM1"); ener2json.add("value", ener2);
  freq2json.add("name", "Frequency PZEM1"); freq2json.add("value", freq2);
  pf2json.add("name", "PF PZEM1"); pf2json.add("value", pf2);

  volt3 = curr3 = powe3 = ener3 = freq3 = pf3 = 0;
  volt1json.add("name", "Voltage PZEM1"); volt3json.add("value", volt3);
  curr3json.add("name", "Current PZEM1"); curr3json.add("value", curr3);
  powe3json.add("name", "Power PZEM1"); powe3json.add("value", powe3);
  ener3json.add("name", "Energy PZEM1"); ener3json.add("value", ener3);
  freq3json.add("name", "Frequency PZEM1"); freq3json.add("value", freq3);
  pf3json.add("name", "PF PZEM1"); pf3json.add("value", pf3);

  volt4 = curr4 = powe4 = ener4 = freq4 = pf4 = 0;
  volt4json.add("name", "Voltage PZEM1"); volt4json.add("value", volt4);
  curr4json.add("name", "Current PZEM1"); curr4json.add("value", curr4);
  powe4json.add("name", "Power PZEM1"); powe4json.add("value", powe4);
  ener4json.add("name", "Energy PZEM1"); ener4json.add("value", ener4);
  freq4json.add("name", "Frequency PZEM1"); freq4json.add("value", freq4);
  pf4json.add("name", "PF PZEM1"); pf4json.add("value", pf4);

  volt5 = curr5 = powe5 = ener5 = freq5 = pf5 = 0;
  volt1json.add("name", "Voltage PZEM1"); volt5json.add("value", volt6);
  curr3json.add("name", "Current PZEM1"); curr5json.add("value", curr6);
  powe3json.add("name", "Power PZEM1"); powe5son.add("value", powe6);
  ener3json.add("name", "Energy PZEM1"); ener5json.add("value", ener6);
  freq3json.add("name", "Frequency PZEM1"); freq5json.add("value", freq6);
  pf3json.add("name", "PF PZEM1"); pf5json.add("value", pf5);

  volt6 = curr6 = powe6 = ener6 = freq6 = pf6 = 0;
  volt6json.add("name", "Voltage PZEM1"); volt6json.add("value", volt6);
  curr6json.add("name", "Current PZEM1"); curr6json.add("value", curr6);
  powe6json.add("name", "Power PZEM1"); powe6json.add("value", powe6);
  ener6json.add("name", "Energy PZEM1"); ener6json.add("value", ener6);
  freq6json.add("name", "Frequency PZEM1"); freq6json.add("value", freq6);
  pf6json.add("name", "PF PZEM1"); pf6json.add("value", pf6);
}

void setup() {
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

}
