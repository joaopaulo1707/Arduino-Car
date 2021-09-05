#include <Servo.h>

// --> --> --> --> GLOBAL VARIABLES <-- <-- <-- <-- 
int direction_status = 0;
int acceleration_status = 1;
int acceleration_time = 0;

// --> --> --> --> MOTORS <-- <-- <-- <--
Servo servo_motor;
int SERVO_PIN = 11;
int DCMOTOR_PIN = 10;
int RELAY_PIN = 9;

int setupmotors() {
    pinMode(SERVO_PIN, OUTPUT);
    pinMode(DCMOTOR_PIN, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);

    servo_motor.attach(SERVO_PIN);
    servo_motor.write(90);
}

int movemotors() {
    
    if (acceleration_status == 1 || acceleration_status == -1) {
        acceleration_time = acceleration_time < 255 ? acceleration_time + 2 : 255;
    } else {
        acceleration_time = 0;
    }

    analogWrite(DCMOTOR_PIN, acceleration_time);
    delay(15);
    servo_motor.write(90 + 90*direction_status);
    delay(15);
    digitalWrite(RELAY_PIN, acceleration_status == 1 ? HIGH : LOW);
	delay(15);
}


// --> --> --> --> Running Section <-- <-- <-- <--
void setup() {
    setupmotors();

}

void loop() {
    movemotors();

}   
