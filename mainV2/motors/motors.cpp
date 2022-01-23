#include "motors.h"

Motors::Motors(int in1, int in2, int in3, int in4, int enA, int enB, int s1, int s2) {
    // in1, ..., in4, enA, enB, s1, s2 
    this->in1=in1; this->in2=in2;
    this->in3=in3; this->in4=in4;
    this->enA=enA; this->enB=enB;
    this->s1=s1; this->s2=s2;
    init();
};
void Motors::init() {
    pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
    pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
    this->servo1.attach(this->s1); this->servo2.attach(this->s2);
    this->values[0] = LOW; this->values[1] = LOW;
    this->values[2] = LOW; this->values[3] = LOW;
    this->values[4] = 0; this->values[5] = 90;
    update();
};
void Motors::update() {
    digitalWrite(in1, this->values[0]); digitalWrite(in2, this->values[1]); 
    digitalWrite(in3, this->values[2]); digitalWrite(in4, this->values[3]);
    analogWrite(enA, this->values[4]); analogWrite(enB, this->values[4]);
    this->servo1.write(this->values[5]); this->servo2.write(this->values[5]);
};
// DC motors
void Motors::front() {
    this->values[0] = HIGH; this->values[1] = LOW;
    this->values[2] = HIGH; this->values[3] = LOW;
};
void Motors::back() {
    this->values[0] = LOW; this->values[1] = HIGH;
    this->values[2] = LOW; this->values[3] = HIGH;
};
// Servo motors
void Motors::left() {
    this->values[5] = 0;
};
void Motors::right() {
    this->values[5] = 180;
};
