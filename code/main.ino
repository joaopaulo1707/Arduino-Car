#include <Servo.h>

// --> --> --> --> GLOBAL VARIABLES <-- <-- <-- <--
int motors_variables[] = {0, 0, 0}; // {direction_status, acceleration_status, acceleration_time}
float distances[] = {0, 0}; // {front_distance, back_distance}

// --> --> --> --> MOTORS <-- <-- <-- <--
Servo servo_motor;
int MOTORS_PINS[] = {11, 10, 9}; // {SERVO_PIN, DCMOTOR_PIN, RELAY_PIN}

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
    servo_motor.write(90 + 90*motors_variables[0]);
    digitalWrite(MOTORS_PINS[2], motors_variables[1] == 1 || motors_variables[1] == -1 ? LOW : HIGH);
    delayMicroseconds(15);
}

// --> --> --> --> DISTANCE SENSORS <-- <-- <-- <--
int DSENSOR_PINS[] = {8, 7}; // {FSENSOR_PIN, BSENSOR_PIN}

int updateDistances() {
    for (int i = 0; i < 1; i++) {
        pinMode(DSENSOR_PINS[i], OUTPUT);
        digitalWrite(DSENSOR_PINS[i], LOW);
        delayMicroseconds(i);
        digitalWrite(DSENSOR_PINS[i], HIGH);
        delayMicroseconds(10);
        digitalWrite(DSENSOR_PINS[i], LOW);
        pinMode(DSENSOR_PINS[i], INPUT);
        distances[i] = 0.0343 * pulseIn(DSENSOR_PINS[i], HIGH) / 2;
    }
}

// --> --> --> --> Running Section <-- <-- <-- <--
void setup() {
    setupMotors();

}

void loop() {
    updateDistances();
    moveMotors();

}   
