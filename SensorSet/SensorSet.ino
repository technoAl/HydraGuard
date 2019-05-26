int tempSens = A9;
int led = 13;
int localSweat[60];
int localTemp[60];
int localMvmnt[60];
int initiationDataSweat[10];
int initiationDataTemp[10];
int counter = 0;
int buzzer = 3;
int tiltSens = 2;
int mvmntIndex = 0;

void setup() {
  Serial1.begin(38400);
  Serial.begin(9600);
  pinMode(A9, INPUT);
  pinMode(led, OUTPUT);
  pinMode(A8, INPUT);
  pinMode(tiltSens, INPUT);
  for(int i = 0;i < 10; i++){
    
    int reading = analogRead(A9);
    float sweatReading = analogRead(A8);
    initiationDataSweat[i] = reading;
    initiationDataTemp[i] = sweatReading;
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    
  }
}

void loop() {
  if(Serial1.available()) {
    char c = Serial1.read();
    if(c == '1'){
      tone(buzzer, 440, 100);
    }else if(c == '2'){
      
    }else{
      
    }
  }
  
  digitalWrite(led, HIGH);
  
  int reading = analogRead(A9);
  float voltage = reading * 3.3 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  float sweatReading = analogRead(A8);
  int mvmntReading = digitalRead(tiltSens);

  int place = counter%60;
  localMvmnt[place] = mvmntReading;
  localSweat[place] = sweatReading;
  localTemp[place] = temperatureF;
  
  // Serial.println(counter);
  Serial1.print("s:");
  Serial1.println(sweatReading);
  //Serial.println(sweatReading);
  Serial1.print("t:");
  Serial1.println(temperatureF);
  Serial1.print("m:");
  Serial.println(mvmntReading);
  //Serial.println(temperatureF);
  counter++; 
  delay(1000);
}
