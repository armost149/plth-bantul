
void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(A7, INPUT);
//  nilai[0] = setZeroCurrent();
}
 
void loop() {
    Serial.println();
    baca_WCS();
//    float currentSekarang = get_current(nilai[0]);
//    nilai[1] = currentSekarang;
//    Serial.print(currentSekarang);
}

void baca_WCS(){
  float averageCurrent = 0, averageVoltage = 0;
  for(int i=0; i< 100; i++)
    {   
      int adc = analogRead(A7);    
      delay(2);
      float arus = adc/66.0;

      averageVoltage += adc;
      averageCurrent += arus;
     }
  averageCurrent /= 100;
  averageVoltage /= 100;
  
  Serial.println(averageVoltage);
  Serial.println(averageCurrent);

  delay(2500);
}

//float get_current(float zeroCurrentValue){
//  float averageSensorValue =0;
//  int sensorValue ;
//  float voltage, current;
//  
//  for(int i=0; i< 100; i++)
//    {   
//      sensorValue = analogRead(14);
//      //Serial.print("S:");Serial.println(sensorValue);      
//      delay(2);
//
//        voltage = (sensorValue) * (5000 /  (pow(2,10)-1)) -( 0.5 * 5000) + 164 ; 
//       //Serial.print("V:");Serial.println(voltage);
//        current  = voltage / 66.0;
// 
//          averageSensorValue += current;
//     }    
//
//    averageSensorValue /= 100;
//    averageSensorValue -= zeroCurrentValue;//subtract the zero current value
//        
//    return averageSensorValue;
//}

//float setZeroCurrent(){
//  float zeroCurrentValue = get_current(0.0);
//  bool zeroCurrentSet = true;    
//  Serial.print("Zero Value Set to: ");
//  Serial.print(zeroCurrentValue);
//  Serial.println("A");
//  Serial.println("*********************");
//  return zeroCurrentValue;
//}
