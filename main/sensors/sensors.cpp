#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTPUT 1

#include "sensors.h"

Sensors::Sensors(int echo1, int trig1) {
    this->echo1 = echo1;
    this->trig1 = trig1;
    init()
}
void Sensors::init() {
    pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
}
void Sensors::update() {
    digitalWrite(trig1, LOW);
    delayMicroseconds(2);
    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig1, LOW)

    this->distance = pulseIn(echo1, HIGH) * 0.034 / 2
}