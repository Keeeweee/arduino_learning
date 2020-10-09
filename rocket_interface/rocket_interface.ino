int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void restBehaviour() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void activeBehaviour() {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  delay(250);

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);

  delay(250);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    restBehaviour();
  }
  else {
    activeBehaviour();
  }
}