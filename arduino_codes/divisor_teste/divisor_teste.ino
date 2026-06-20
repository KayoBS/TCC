float converter = (5.f / 1024.f);

void clear();
float get_voltage();

void setup() {
  Serial.begin(9600);
}

void loop() {
  clear();
  Serial.print( get_voltage() ) ;
  Serial.println(" V");
  delay(100);
}

void clear() {
  Serial.print("\x1B[H\x1B[2J");
}

float get_voltage() {
  return (analogRead(A3) * converter * 2.f);
}
