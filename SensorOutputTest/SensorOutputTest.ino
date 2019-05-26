int rx = 0;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(38400);
  pinMode(led, OUTPUT);
  //pinMode(rx, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(led,HIGH);
  Serial1.print("s:"); 
  Serial1.println("5");
}


