#include <Servo.h>


#define trigPin 10
#define echoPin 9
#define ledPin 7
#define ledPin2 6

long unsigned duration=0;
int distance ;
int safetyDistance;

Servo myservo;

int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration = pulseIn(echoPin, HIGH,30000);
  delay(200);
  distance = duration*0.034/2;
  safetyDistance = distance;
if (safetyDistance <= 10){
  digitalWrite(ledPin, HIGH);
  delay(8000);
  digitalWrite(ledPin, LOW);
  delay(2000);
  digitalWrite(ledPin2, HIGH);
  delay(4000);
  digitalWrite(ledPin2, LOW);
  delay(2000);
}
else{
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
}

}

void setup()
{
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(8);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 int i ;
 for (i=15; i<=165; i++)
 {
  myservo.write(i);
  delay(15);
  calculateDistance();
  //Serial.print(i);
  //Serial.print(",");
  Serial.print(distance);
  Serial.println();
 }

 for(i=165; i>=15; i--)
 {
  myservo.write(i);
  delay(15);
  calculateDistance();
  //Serial.print(i);
  //Serial.print(",");
  Serial.print(distance);
  Serial.println();
  
 }
  

}
