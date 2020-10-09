const int sensorPin = A0;
const float baseTemp = 20.0;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void setState(int first, int second, int third) {
  digitalWrite(2, first);
  digitalWrite(3, second);
  digitalWrite(4, third);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(" , Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - 0.5) * 100;

  Serial.print(" , degrees C: ");
  Serial.print(temperature);

  if (temperature < 20) {
    setState(LOW, LOW, LOW);
  }
  else if (temperature < 25) {
    setState(HIGH, LOW, LOW);
  }
  else if (temperature < 30) {
    setState(HIGH, HIGH, LOW);
  }
  else {
    setState(HIGH, HIGH, HIGH);
  }

  Serial.println();

  delay(500);
}
