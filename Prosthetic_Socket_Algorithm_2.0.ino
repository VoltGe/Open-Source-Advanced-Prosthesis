  int sensorPin1 = A0;    // select the input pin for temp ic           -------->  TOP
  int sensorPin2 = A1;    // select the input pin for temp ic           -------->  MIDDLE
  int sensorPin3 = A2;    // select the input pin for temp ic           -------->  BOTTOM
  int sensorValue = 0;

  
  int tecpin1 = 1;      // select the pin for the tec1           -------->  TOP
  int tecpin2 = 2;      // select the pin for the tec1           -------->  TOP
  int tecpin3 = 3;      // select the pin for the tec2           -------->  MIDDLE
  int tecpin4 = 4;      // select the pin for the tec2           -------->  MIDDLE
  int tecpin5 = 5;      // select the pin for the tec3           -------->  BOTTOM
  int tecpin6 = 6;      // select the pin for the tec3           -------->  BOTTOM
#define aref_voltage 3.3         // we tie 3.3V to ARef and measure it with a multimeter!

void setup() {
  
  //declare tec's as outputs
  pinMode(tecpin1, OUTPUT);
  pinMode(tecpin2, OUTPUT);
  pinMode(tecpin3, OUTPUT);
  pinMode(tecpin4, OUTPUT);
  pinMode(tecpin5, OUTPUT);
  pinMode(tecpin6, OUTPUT);
}

void loop() {
  /////////////////TMP36'S
  
  sensorValue = analogRead(sensorPin1);
  if (A0 < 70) digitalWrite (tecpin1, HIGH) ; // 35 degrees fahrenheit
  if (A0 > 95) digitalWrite (tecpin2, HIGH) ; // 85 degrees fahrenheit
  else digitalWrite (tecpin1 & tecpin2, LOW);
 
  sensorValue = analogRead(sensorPin2);
  if (A1 < 70) digitalWrite (tecpin3, HIGH) ; 
  if (A1 > 95) digitalWrite (tecpin4, HIGH) ; 
  else digitalWrite (tecpin3 & tecpin4, LOW);

  
  sensorValue = analogRead(sensorPin3);
  if (A2 < 70) digitalWrite (tecpin5, HIGH) ; 
  if (A2 > 95) digitalWrite (tecpin6, HIGH) ; 
  else digitalWrite (tecpin5 & tecpin6, LOW);
  
}
