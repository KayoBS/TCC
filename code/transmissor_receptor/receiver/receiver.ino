//receiver.ino AA (Arduino to Arduino)
/*tem como objetivo receber as mensagens do sender
e ligar um LED a depender da tensão lida por ele*/

#include <SoftwareSerial.h>
#include "type_data.h"

const int ledPin = 13;

SoftwareSerial receiver(8, 9); //RX TX
Data data;

void flash( int rate );

void setup() {
  pinMode(ledPin, OUTPUT);
  receiver.begin(9600);
}

void loop() {
  if(receiver.available() > 1) {
    data.h_byte = receiver.read();
    data.l_byte = receiver.read();
    concat_bytes(&data);
  }
  flash(data.value);
}

void flash( int rate ) {
  //0 -> lento e 1023 -> muito rápido
  int period = (50 + (1023 - rate) / 4);
  digitalWrite(ledPin, 1);
  delay(period);
  digitalWrite(ledPin, 0);
  delay(period);
}