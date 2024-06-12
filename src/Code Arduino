#include <Pixy2.h>
#include <Servo.h>

Pixy2 pixy;
Servo myservo;

// Define the control pins for the L298N motor driver
int motorLeftPin1 = 37;  // Left motor forward
int motorLeftPin2 = 38;  // Left motor backward
int motorRightPin1 = 39; // Right motor forward
int motorRightPin2 = 40; // Right motor backward
// Optional PWM pins
int motorLeftPWM = 9;
int motorRightPWM = 10;

int numLaps = 0;
const int maxLaps = 3;
int yellowLinesDetected = 0; // Counter for yellow lines detected
int blueLinesDetected = 0; // Counter for blue lines detected

void setup() {
  Serial.begin(115200);
  pixy.init();
  myservo.attach(3); // Pin for the servo motor

  // Set the motor control pins as output
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);
  pinMode(motorLeftPWM, OUTPUT);
  pinMode(motorRightPWM, OUTPUT);
}

void loop() {
  pixy.ccc.getBlocks();
  
  if (pixy.ccc.numBlocks) {
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      if (pixy.ccc.blocks[i].m_signature == 1) { // Yellow line detected
        yellowLinesDetected++;
        turnLeft();
        delay(500); // Adjust delay to ensure the turn is completed
        myservo.write(90); // Reset servo to straight position
      } else if (pixy.ccc.blocks[i].m_signature == 2) { // Blue line detected
        blueLinesDetected++;
        turnRight();
        delay(500); // Adjust delay to ensure the turn is completed
        myservo.write(90); // Reset servo to straight position
      }
    }
  }

  moveForward();
  delay(100); // Adjust time to avoid looping jumps

  // Check if a full lap is completed
  if (checkLapComplete()) {
    numLaps++;
    yellowLinesDetected = 0; // Reset yellow line counter
    blueLinesDetected = 0; // Reset blue line counter
    if (numLaps == maxLaps) {
      stopMotors();
      while (1); // Stop the program
    }
  }
}

void turnLeft() {
  // Turn left by stopping the right motor and running the left motor forward
  analogWrite(motorLeftPWM, 255); // Full speed
  digitalWrite(motorLeftPin1, HIGH);
  digitalWrite(motorLeftPin2, LOW);
  
  analogWrite(motorRightPWM, 255); // Full speed
  digitalWrite(motorRightPin1, LOW);
  digitalWrite(motorRightPin2, LOW);
}

void turnRight() {
  // Turn right by stopping the left motor and running the right motor forward
  analogWrite(motorLeftPWM, 255); // Full speed
  digitalWrite(motorLeftPin1, LOW);
  digitalWrite(motorLeftPin2, LOW);
  
  analogWrite(motorRightPWM, 255); // Full speed
  digitalWrite(motorRightPin1, HIGH);
  digitalWrite(motorRightPin2, LOW);
}

void moveForward() {
  analogWrite(motorLeftPWM, 255); // Full speed
  digitalWrite(motorLeftPin1, HIGH);
  digitalWrite(motorLeftPin2, LOW);
  
  analogWrite(motorRightPWM, 255); // Full speed
  digitalWrite(motorRightPin1, HIGH);
  digitalWrite(motorRightPin2, LOW);
}

void stopMotors() {
  analogWrite(motorLeftPWM, 0);
  analogWrite(motorRightPWM, 0);
  
  digitalWrite(motorLeftPin1, LOW);
  digitalWrite(motorLeftPin2, LOW);
  digitalWrite(motorRightPin1, LOW);
  digitalWrite(motorRightPin2, LOW);
}

bool checkLapComplete() {
  // Check if the required number of yellow and blue lines for a full lap are detected
  return (yellowLinesDetected >= 4 && blueLinesDetected >= 4);
}
