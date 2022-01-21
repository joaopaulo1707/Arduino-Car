
#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include <Servo.h>

class Motors {
    private:
        int in1, in2, in3, in4, enA, enB, s1, s2;
    public:
        Motors(int in1, int in2, int in3, int in4, int enA, int enB, int s1, int s2);
        int values[6]; Servo servo1; Servo servo2;
        void init(), update();
        void front(), back();
        void left(), right();
};

#endif