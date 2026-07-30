int ldrPin = A0;
int tempPin = A1;
int pirPin = 2;

int light = 8;
int fan = 9;
int buzzer = 10;

void setup()
{
  pinMode(pirPin, INPUT);

  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int ldrValue = analogRead(ldrPin);
  int pirValue = digitalRead(pirPin);

  // Temperature calculation
  int tempReading = analogRead(tempPin);

  float voltage = tempReading * 5.0 / 1023.0;
  float temperature = (voltage - 0.5) * 100;


  Serial.print("Temperature: ");
  Serial.println(temperature);


  // Automatic light control
  if(ldrValue < 500)
  {
    digitalWrite(light, HIGH);   // Night - ON
  }
  else
  {
    digitalWrite(light, LOW);    // Day - OFF
  }


  // Fan control using temperature
  if(temperature > 30)
  {
    digitalWrite(fan, HIGH);
  }
  else
  {
    digitalWrite(fan, LOW);
  }


  // Security alert
  if(pirValue == HIGH)
  {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
