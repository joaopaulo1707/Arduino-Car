#include <Servo.h>

// --> --> --> --> GLOBAL VARIABLES <-- <-- <-- <-- 
int direction_status = 0;

// --> --> --> --> MOTORS <-- <-- <-- <--
Servo servo_motor;
int SERVO_PIN = 13;

int setupmotors() {
    servo_motor.attach(SERVO_PIN);
    servo_motor.write(90);
}

int movemotors() {
    servo_motor.write(90 + 90*direction_status);
    delay(15);
}


// --> --> --> --> Running Section <-- <-- <-- <--
void setup() {
    setupmotors();

}

void loop() {
    movemotors();

}   
