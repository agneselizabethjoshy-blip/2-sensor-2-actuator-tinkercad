int tempSensor = A0;
int ldrSensor = A1;

int led = 13;
int motor = 9;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int tempValue = analogRead(tempSensor);
  int lightValue = analogRead(ldrSensor);

  Serial.print("Temperature: ");
  Serial.println(tempValue);

  Serial.print("Light: ");
  Serial.println(lightValue);

  // Temperature controls motor
  if (tempValue > 300) {
    digitalWrite(motor, HIGH);
  } 
  else {
    digitalWrite(motor, LOW);
  }

  // LDR controls LED
  if (lightValue < 500) {
    digitalWrite(led, HIGH);
  } 
  else {
    digitalWrite(led, LOW);
  }

  delay(500);
}
