#include <Servo.h>

int STATUS_VARIABLES[] = {0, 0, 0}; // {direction, acceleration, colliding}
float FLOAT_VARIABLES[] = {0}; // {front distance}

// ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> --->

int __MOTORS[] = {13, 12, 11}; // {relay, DCs, servo}
Servo servo_motor;

int SetupMotors() {
    pinMode(__MOTORS[0], OUTPUT); pinMode(__MOTORS[1], OUTPUT);
    servo_motor.attach(__MOTORS[2]);
}

int MoveMotors() {
    if (STATUS_VARIABLES[2] == 0) {
        digitalWrite(__MOTORS[0], STATUS_VARIABLES[1] == 1 ? HIGH : LOW);
        digitalWrite(__MOTORS[1], abs(STATUS_VARIABLES[1]));
        servo_motor.write(90 * (1 + STATUS_VARIABLES[0]));
    } else if (STATUS_VARIABLES[2] == 1) {
        digitalWrite(__MOTORS[0], HIGH);
        digitalWrite(__MOTORS[1], HIGH);
        servo_motor.write(180);
    }
    delay(15);
}

// ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> --->

int __SENSORS[] = {10, 9}; // {trigger, echo}

int SetupSensors() {
	pinMode(__SENSORS[0], OUTPUT);
	pinMode(__SENSORS[1], INPUT);
}

int UpdateSensors() {
    digitalWrite(__SENSORS[0], LOW);
    delayMicroseconds(5);        
    digitalWrite(__SENSORS[0], HIGH);  
    delayMicroseconds(10);      
    digitalWrite(__SENSORS[0], LOW);
    FLOAT_VARIABLES[0] = pulseIn(__SENSORS[1], HIGH) / 58;
}

// ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> --->

void setup()
{
    SetupMotors();
    SetupSensors();
}

void loop()
{
    MoveMotors();
    UpdateSensors();
}
