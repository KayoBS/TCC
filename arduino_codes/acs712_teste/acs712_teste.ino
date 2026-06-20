const float converter = (5.f / 1024.f);

class acs712 {
  private:
    byte pin;
    acs712() {}

  public:
    acs712( byte pin ) : pin(pin) {
      pinMode(this->pin, INPUT);
    }

    float getvolts() {
      return (analogRead(pin) * converter);
      //return (analogRead(pin) * converter) - 2.5f;
    }

    float getamps() {
      return ( ((this->getvolts() -2.5f) *1000) / 185.f); //miliamperes
      //return (this->getvolts() / 185.f); //miliamperes
    }

};

void clear();

acs712 sensor(A3);

void setup() {
  Serial.begin(9600);
  Serial.println("Medicao iniciada");
}

void loop() {
  clear();
  Serial.print(sensor.getvolts());
  Serial.print("V ~ ");
  Serial.print(sensor.getamps());
  Serial.println("mA");
  delay(100);
}

void clear() {
  Serial.print("\x1B[H\x1B[2J");
}
