#include <ArduinoSTL.h>
#include "lib.h"

acs712 sensor(A3);

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando calibração, certifique-se de que não há corrente no momento");
  delay(100);
  sensor.calibrate();
  delay(1000);

  Serial.println("Medicao iniciada");
}

void loop() {
  //Terminal::clear();
  //std::cout << "Corrente em A3: " << sensor.getamps() << "A\n";
  //std::printf("Corrente em A3: %dA\n", sensor.getamps());
  Serial.print("Corrente em A3: ");
  Serial.print(sensor.getamps());
  Serial.println("A");
  delay(100);
}