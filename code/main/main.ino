#include <Servo.h>

int STATUS_VARIABLES[] = {0, 0, 0}; // {direction, acceleration, colliding}
float FLOAT_VARIABLES[] = {0}; // {front distance}

// ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> --->

int __MOTORS[] = {8, 7, 6, 5, 9, 4, 3}; // {In1, In2, In3, In4, EnA, EnB, Servo}
Servo servo_motor;

int SetupMotors() {
    pinMode(__MOTORS[4], OUTPUT);
    pinMode(__MOTORS[5], OUTPUT);
    pinMode(__MOTORS[0], OUTPUT);
    pinMode(__MOTORS[1], OUTPUT);
    pinMode(__MOTORS[2], OUTPUT);
    pinMode(__MOTORS[3], OUTPUT);

    servo_motor.attach(__MOTORS[6]);
}

int stop() {
    digitalWrite(__MOTORS[0], LOW);
    digitalWrite(__MOTORS[1], LOW);
    digitalWrite(__MOTORS[2], LOW);
    digitalWrite(__MOTORS[3], LOW);
}
int foward() {
    digitalWrite(__MOTORS[0], HIGH);
    digitalWrite(__MOTORS[1], LOW);
    digitalWrite(__MOTORS[2], HIGH);
    digitalWrite(__MOTORS[3], LOW);
}
int reverse() {
    digitalWrite(__MOTORS[0], LOW);
    digitalWrite(__MOTORS[1], HIGH);
    digitalWrite(__MOTORS[2], LOW);
    digitalWrite(__MOTORS[3], HIGH);
}

int MoveMotors() {
    if (Serial.read() == "F") {
        foward();
    } else if (Serial.read == "B") {
        reverse();
    } else if (Serial.read == "L") {
        servo_motor.write(0);
    } else if (Serial.read == "R") {
        servo_motor.write(180);
    } else {
        stop();
        servo_motor.write(90);
    }

}

// ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> ---> --->

int __SENSORS[] = {11, 10}; // {trigger, echo}

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
