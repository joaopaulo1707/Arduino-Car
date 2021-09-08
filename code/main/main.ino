#include <Servo.h>

// --> --> --> --> GLOBAL VARIABLES <-- <-- <-- <--
int motors_variables[] = {0, 0, 0}; // {direction, acceleration, acceleration time}
float distances[] = {0, 0}; // {front distance, back distance}

// --> --> --> --> MOTORS <-- <-- <-- <--
Servo servo_motor;
int MOTORS_PINS[] = {11, 10, 9}; // {SERVO PIN, DCMOTOR PIN, RELAY PIN}

int setupMotors() {
    pinMode(MOTORS_PINS[1], OUTPUT); pinMode(MOTORS_PINS[2], OUTPUT);

    servo_motor.attach(MOTORS_PINS[0]);
    servo_motor.write(90);
}

int moveMotors() {
    if (motors_variables[1] == 1 || motors_variables[1] == -1)
        motors_variables[2] = motors_variables[2] < 255 ? motors_variables[2] + 4 : 255;
    else motors_variables[2] = 0;

    analogWrite(MOTORS_PINS[1], motors_variables[2]);
    servo_motor.write(90 + 90 * motors_variables[0]);
    digitalWrite(MOTORS_PINS[2], motors_variables[1] == 1 || motors_variables[1] == -1 ? LOW : HIGH);
    delayMicroseconds(15);
}

// --> --> --> --> DISTANCE SENSORS <-- <-- <-- <--
int DSENSOR_PINS[] = {8, 7, 6, 5}; // {FSENSOR PIN, BSENSOR PIN}

int setupDSensors() {
    pinMode(DSENSOR_PINS[0], OUTPUT);
    pinMode(DSENSOR_PINS[1], INPUT);
    pinMode(DSENSOR_PINS[2], OUTPUT);
    pinMode(DSENSOR_PINS[3], INPUT);
}

int updateDistances() {
    for (int i = 0; i < 3; i += 2) {
        digitalWrite(DSENSOR_PINS[i], LOW);
        delayMicroseconds(2);
        digitalWrite(DSENSOR_PINS[i], HIGH);
        delayMicroseconds(10);
        digitalWrite(DSENSOR_PINS[i], LOW);
        distances[i] = 0.0343 * pulseIn(DSENSOR_PINS[i + 1], HIGH) / 2;
    }
}

// --> --> --> --> Running Section <-- <-- <-- <--
void setup() {
    setupMotors();
    setupDSensors();

}

void loop() {
    updateDistances();
    moveMotors();

}   
