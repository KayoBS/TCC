//sender.ino AA (Arduino to Arduino)
/*tem como objetivo ler uma porta analógica com um
potenciômetro e enviar essas mensagens para uma
placa esp32*/

#include <SoftwareSerial.h>
#include "type_data.h"

const int readPin = A1;
const int vccPin  = A2; //power pin para o pot
const int gndPin  = A0;

SoftwareSerial sender(8, 9); //RX TX
Data data;

void setup() {
  pinMode( gndPin, OUTPUT );
  pinMode( vccPin, OUTPUT );
  digitalWrite( vccPin, 1 );
  sender.begin(9600);
}
void loop() {
  data.value = analogRead(readPin);
  sprt_ones(&data);
  sender.write(data.h_byte);
  sender.write(data.l_byte);
  delay(1000);
}