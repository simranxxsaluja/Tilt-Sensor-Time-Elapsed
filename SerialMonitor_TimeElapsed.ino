float passedTime;

int led = 3, tilt = 4, buzzer = 5;

void (*resetFunc)(void) = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tilt, INPUT);
}

void loop() {
  if (digitalRead(tilt) == HIGH) {
    Serial.println("*****Tilt Detected******");

    for (int i = 300; i <= 700; i = i + 20) {
     digitalWrite(led, HIGH);
     tone(buzzer, i);
     delay(30);
     digitalWrite(led, LOW);
     noTone(buzzer);
     delay(30);
    }
     resetFunc();
  }
  
  else {
    Serial.print("Time: ");
    passedTime = millis();
    Serial.println(passedTime);
    delay(1000);
  }
}
