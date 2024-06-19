#include "Test.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>

void initLibrary() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void doSomething() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
