#include <motors.h>
#include <sensors.h>

// --> --> --> --> --> --> --> --> Variables

int time = 0;
char junk;
String inputString = "";

Motors controler(5, 4, 3, 2, 6, 9, A0, A1);
Sensors sensors(12, 13);

// --> --> --> --> --> --> --> --> Working
void setup()
{
    Serial.begin(9600);
};
void loop()
{
    if (Serial.available()) {
        while (Serial.available()) {
            inputString += (char)Serial.read();
        };
        Serial.println(inputString);
        while (Serial.available()) {
            junk = Serial.read();
        };
        if (inputString == "F") { controler.front(); }
        else if (inputString == "B") { controler.back(); }
        else if (inputString == "L") { controler.left(); }
        else if (inputString == "R") { controler.right(); }
        inputString = "";
    }
    if (time % 20 == 0) { controler.update(); };
    if (time % 20 == 0) { sensors.update(); };
    time += 1;
};
