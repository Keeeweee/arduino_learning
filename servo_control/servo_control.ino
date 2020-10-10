#include<Servo.h>

Servo myServo;

const int potPin = A0;
const int servoPin = 9;

int potValue;
int angle;


void setup() {
  myServo.attach(9);

  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  Serial.print("potValue: ");
  Serial.print(potValue);
  
  angle = map(potValue, 0, 1023, 0, 179);

  Serial.print(" , angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
