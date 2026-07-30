int ldr = A0;
int pir = 2;
int led = 13;
int buzzer = 8;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int light = analogRead(ldr);
  int motion = digitalRead(pir);

  if (light < 500 && motion == HIGH) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  } 
  else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
}
