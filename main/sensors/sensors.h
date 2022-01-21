
#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class Sensors {
    private:
        int echo1, trig1;
    public:
        Sensors(int echo1, int trig1);
        float distance;
        void init(), update();
};

#endif