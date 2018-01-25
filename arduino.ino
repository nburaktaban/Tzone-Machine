const int analogOutPin = 6;

void setup() {
  Serial.begin(9600);
  TCCR0B = (TCCR0B & 0xF8) | 1;
}

void loop() {
  if (Serial.available()) {
    double sensorValue = Serial.readString().toDouble();
    motor(sensorValue); 
  }
  delay(2);
}

void motor(double value){
  analogWrite(analogOutPin, value);
  //Serial.println(value);
}
