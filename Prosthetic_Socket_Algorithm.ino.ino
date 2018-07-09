 #include <Servo.h>
 Servo servo1;
 Servo servo2;
 Servo servo3;
 int reading1;   
 int reading2; 
 int reading3; 

int sensorPin  = A0;    // select the input pin for the battery
int sensorValue = 0;  // variable to store the value coming from the sensor(s)
int haptic = 15;      // select the pin for the haptic

void setup(void) {
  
  pinMode(haptic, OUTPUT);  ///// for battery
  // //BMS (Battery Management System)
  sensorValue = analogRead(sensorPin); //.0049 volts (4.9 mV) per unit 
  if (A0 == 378) 
 {
 digitalWrite (haptic, HIGH); delay(200); 
 digitalWrite (haptic, HIGH); delay(200);
 delay(60*1000*45);
 }
  
  if (A0 == 189) ; //1010 = 4.9 volts (about)
{
digitalWrite (haptic, HIGH); delay(200);
digitalWrite (haptic, HIGH); delay(200);
digitalWrite (haptic, HIGH); delay(200);
digitalWrite (haptic, HIGH); delay(200); 
delay(60*1000*45);
}   
   if (189<A0<378) digitalWrite (haptic, LOW);
   if (378<A0) digitalWrite (haptic, LOW);
   if (189>A0) digitalWrite (haptic, LOW);
 
 //---------------------------------------------------------------------
 Serial.begin(9600);   
 servo1.attach(9); //servo at digital pin 9
 servo1.write(0); //initial point for servo
 servo2.attach(10); //servo at digital pin 10
 servo2.write(0); //initial point for servo
 servo3.attach(11); //servo at digital pin 11
 servo3.write(0); //initial point for servo

}
 
void loop(void) {
  reading1 = analogRead(A1); //top fsr
  reading2 = analogRead(A2); //middle fsr
  reading3 = analogRead(A3); //bottom fsr
 
 
  int value1 = map(reading1, 0, 500, 135, 90); //side servo
  servo1.write(value1);

  int value2 = map(reading2, 0, 600, 160, 120); //middle servo
  servo2.write(value2);

  int value3 = map(reading3, 0, 500, 135, 90); //side servo
  servo3.write(value3);
 
  delay(50);
}
