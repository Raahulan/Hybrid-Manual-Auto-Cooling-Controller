// Hybrid Manual/Auto Cooling Controller - Arduino UNO / Wokwi
// D9 is a PWM output represented by a green LED in this simulation.
// A real fan/motor requires an appropriate driver; never connect it directly to D9.
const int modeSwitch = 2;
const int potPin = A0;
const int motorPin = 9;
const int indicatorLED = 13;

void setup() {
  pinMode(modeSwitch, INPUT); // Slide switch connects D2 to 5V or GND
  pinMode(motorPin, OUTPUT);
  pinMode(indicatorLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int mode = digitalRead(modeSwitch);

  if (mode == HIGH) { // MANUAL MODE
    int potValue = analogRead(potPin);
    int pwmValue = map(potValue, 0, 1023, 0, 255);
    analogWrite(motorPin, pwmValue);
    digitalWrite(indicatorLED, LOW);
    Serial.print("MANUAL MODE | Pot: ");
    Serial.print(potValue);
    Serial.print(" | PWM: ");
    Serial.println(pwmValue);
  } else { // AUTO MODE: fixed 50% PWM, blinking status LED
    analogWrite(motorPin, 128);
    digitalWrite(indicatorLED, HIGH);
    delay(500);
    digitalWrite(indicatorLED, LOW);
    delay(500);
    Serial.println("AUTO MODE | Motor = 50%");
  }
}
