#include <WiFi.h>
#include <ThingSpeak.h>
#include "credentials.h"
#include "led.h"

#define WIFI_SSID NETWORK
#define WIFI_PSWD PASSWORD
#define THINGSPEAK_TIME_INTERVAL 20000 //intervalo de espera de uma "requisição" para outra

//unsigned long??
unsigned long channel_number = 3510622;
const char* write_api_key = WRITEKEY;
const char* read_api_key  = READKEY;

unsigned long last_time, actual_time;
bool receive_or_send = false;

Led led(2, false);
WiFiClient client;

unsigned long dt(void);
void connect_wifi(void);

void setup() {
    led.begin();
    Serial.begin(115200);
    delay(50);

    connect_wifi();

    last_time = 0;
    ThingSpeak.begin(client);
}

void loop() {
    actual_time = millis();

    if(dt() > THINGSPEAK_TIME_INTERVAL) {
        if(receive_or_send) {
            //lê os dados do ThinkerSpeak
            int val = ThingSpeak.readIntField(channel_number, 1, read_api_key);
            Serial.print("Value of LEDs Digital State of ThingSpeak: ");
            Serial.println(val);
            led.set_state((bool)val);
        }

        else {
            led.toggle_state();
            //envia dados para o ThinkerSpeak
            ThingSpeak.setField(1, led.get_state());
            ThingSpeak.writeFields(channel_number, write_api_key);
            Serial.print("Value send to ThinkerSpeak: ");
            Serial.println(led.get_state());
        }
    }
}

unsigned long dt(void) {
    return (actual_time - last_time);
}

void connect_wifi(void) {
    Serial.println("Connecting to Wifi network");

    WiFi.begin(WIFI_SSID, WIFI_PSWD);

    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.print("\nWifi connected on IP: ");
    Serial.println(WiFi.localIP());
}
