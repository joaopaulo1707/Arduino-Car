#include <Servo.h>

// --> --> --> --> --> --> --> --> Variables
int time = 0;
char junk;
String inputString = "";

// in1,..., in4, speed(enA, enB), angle
int values[] = {LOW, LOW, LOW, LOW, 0, 90};
float distance = 0;
Servo servo1; Servo servo2;

// --> --> --> --> --> --> --> --> Motors functions
void initMotors() {
    pinMode(5, OUTPUT); pinMode(4, OUTPUT);
    pinMode(3, OUTPUT); pinMode(2, OUTPUT);
    pinMode(6, OUTPUT); pinMode(9, OUTPUT);

    servo1.attach(A0); servo2.attach(A1);
    updateMotors();
};
void updateMotors() {
    digitalWrite(5, values[0]); digitalWrite(4, values[1]); 
    digitalWrite(3, values[2]); digitalWrite(2, values[3]);
    analogWrite(6, values[4]); analogWrite(9, values[4]);
    servo1.write(values[5]); servo2.write(values[5]);
};

// DC motors
void front() {
    values[0] = HIGH; values[1] = LOW;
    values[2] = HIGH; values[3] = LOW;
};
void back() {
    values[0] = LOW; values[1] = HIGH;
    values[2] = LOW; values[3] = HIGH;
};
// Servo motors
void left() {
    values[5] = 0;
};
void right() {
    values[5] = 180;
};

// --> --> --> --> --> --> --> --> Sensors functions

void initSensors() {
    pinMode(12, OUTPUT); pinMode(13, INPUT);
};
void updateSensors() {
    digitalWrite(13, LOW);
    delayMicroseconds(2);
    digitalWrite(13, HIGH);
    delayMicroseconds(10);
    digitalWrite(13, LOW);

    distance = pulseIn(12, HIGH) * 0.034 / 2;
};

// --> --> --> --> --> --> --> --> Working
void setup()
{
    initMotors();
    initSensors();
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
        if (inputString == "F") { front(); }
        else if (inputString == "B") { back(); }
        else if (inputString == "L") { left(); }
        else if (inputString == "R") { right(); }
        inputString = "";
    };
    if (time % 20 == 0) { updateMotors(); };
    if (time % 20 == 0) { updateSensors(); };
    time += 1;
};
