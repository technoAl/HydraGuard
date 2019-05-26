#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);
String serialData = "";
String serialData2 = "";

char c = ' ';

void setup() {
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(9, HIGH);
  Serial.begin(38400);
  Serial.println("Yes");
  bt.begin(38400);
  bt.print("AT+RESET\n\r");
  // put your setup code here, to run once:

}

void loop() {

  if (bt.available())
    {  
        c = bt.read();
        Serial.write(c);
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        bt.write(c);
        Serial.write(c);  
    }

  
//  if (bt.available()) {
//    while (bt.available() > 0) {
//      char inChar = (char)bt.read();
//      serialData2 += inChar;
//    }
//    Serial.print(serialData2);
//    serialData2 = "";
//  }
//  if (Serial.available()) {
//    while (Serial.available() > 0) {
//      char inChar = (char)Serial.read();
//      serialData += inChar;
//    }
//    bt.print(serialData);
//    Serial.print(serialData);
//    serialData = "";
//  }
}
