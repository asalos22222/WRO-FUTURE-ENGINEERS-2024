#include <Servo.h>

const int TRIGGER_PIN_FRONT = 30;  // Front sonar sensor trigger pin
const int ECHO_PIN_FRONT = 31;     // Front sonar sensor echo pin

const int TRIGGER_PIN_LEFT = 32;  // Left sonar sensor trigger pin
const int ECHO_PIN_LEFT = 33;     // Left sonar sensor echo pin

const int TRIGGER_PIN_RIGHT = 34;  // Right sonar sensor trigger pin
const int ECHO_PIN_RIGHT = 35;     // Right sonar sensor echo pin

const int motorPWM = 5;  // PWM pin for the motor

Servo steeringServo;

const int forwardSpeed = 255;  // Adjust this value for the desired forward speed
const int turnSpeed = 255;     // Adjust this value for the desired turn speed


// Stop the car if pulse count is greater than 34000
int lapCount = 1;
const int totalLaps = 3;  // Set the total number of laps

void setup() {
  Serial.begin(9600);
  steeringServo.attach(9);

  // Motor
  pinMode(motorPWM, OUTPUT);

  // Sonar Sensors
  pinMode(TRIGGER_PIN_FRONT, OUTPUT);
  pinMode(ECHO_PIN_FRONT, INPUT);
  pinMode(TRIGGER_PIN_LEFT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
  pinMode(TRIGGER_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_RIGHT, INPUT);


}

void loop() {
  int distanceFront = getDistance(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT);
  int distanceLeft = getDistance(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT);
  int distanceRight = getDistance(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT);

  // Print sensor readings
  Serial.print("Front Distance: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Left Distance: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Right Distance: ");
  Serial.print(distanceRight);
  Serial.print(" cm, Current position: ");
 

  // Implement obstacle avoidance based on sensor readings
  if (distanceFront >= 0 && distanceFront <= 50) {
    // Obstacle avoidance logic
    if (distanceRight > distanceLeft) {
      steeringServo.write(50);
      moveForward(turnSpeed);
      delay(200);
    } else if (distanceLeft > distanceRight) {
      steeringServo.write(140);
      moveForward(turnSpeed);
      delay(200);
    }
  } 
  // Obstacle avoidance logic when distanceFront is greater than or equal to 40
  if (distanceFront >= 0 && distanceFront >= 30) {
    if (distanceRight > distanceLeft) {
      steeringServo.write(80);
      moveForward(turnSpeed);
      delay(20);
    } else if (distanceLeft > distanceRight) {
      steeringServo.write(110);
      moveForward(turnSpeed);
      delay(20);
    }
  }

  // Critical turn
  if (distanceRight < 25) {
    steeringServo.write(110);
    moveForward(turnSpeed);
    delay(10);
  } else if (distanceLeft < 25) {
    steeringServo.write(80);
    moveForward(turnSpeed);
    delay(10);
  }
}

int getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(triggerPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;
  return distance;
}

void moveForward(int speed) {
  digitalWrite(motorPWM, HIGH);
  digitalWrite(26,HIGH);
  digitalWrite(28,LOW);

}

void moveBack(int speed) {
  digitalWrite(motorPWM, HIGH);
  digitalWrite(26,LOW);
  digitalWrite(28,HIGH);
}
