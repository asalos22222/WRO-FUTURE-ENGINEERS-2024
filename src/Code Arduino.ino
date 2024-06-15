#include <Servo.h>
#include <movingAvg.h>

const int servoPin = 9;

int _output_PD5 = 43;
int _output_PD4 = 45;
int _output_PD7 = 41;
int _output_PD6 = 39;
int _output_PWM10 = 11;
int _output_PWM9 = 10;

const int trigPin = 12;
const int echoPin = 13;

int intunecat = 610;
int luminos = 510;

bool isturning = 0;
unsigned long turnmillis = 0;

Servo myservo;
movingAvg mySensor(10);

void setup() {
    pinMode(_output_PD5, OUTPUT);
    pinMode(_output_PD4, OUTPUT);
    pinMode(_output_PD7, OUTPUT);
    pinMode(_output_PD6, OUTPUT);
    pinMode(_output_PWM10, OUTPUT);
    pinMode(_output_PWM9, OUTPUT);
    pinMode(A0, INPUT);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    myservo.attach(servoPin);
    delay(100);
    myservo.write(90);
    delay(100);
    mySensor.begin();

    Serial.begin(9600);
}

void inainte() {
    myservo.write(90);
    digitalWrite(_output_PD4, LOW);
    digitalWrite(_output_PD5, HIGH);
    digitalWrite(_output_PD6, LOW);
    digitalWrite(_output_PD7, HIGH);
    analogWrite(_output_PWM9, 100);
    analogWrite(_output_PWM10, 100);
}

void turnLeft() {
    myservo.write(45);
    digitalWrite(_output_PD4, LOW);
    digitalWrite(_output_PD5, HIGH);
    digitalWrite(_output_PD6, LOW);
    digitalWrite(_output_PD7, HIGH);
    analogWrite(_output_PWM9, 100);
    analogWrite(_output_PWM10, 100);
}

void loop() {
    unsigned long currentmillis = millis();
    int sensorData = analogRead(A0);
    int sensorMovingAvg = mySensor.reading(sensorData);

    Serial.println(sensorMovingAvg);

    if (sensorMovingAvg > 590) {
        isturning = 1;
        turnmillis = currentmillis;
    }

    if (currentmillis - turnmillis > 1950) {
        isturning = 0;
    }

    if (isturning) {
        turnLeft();
        mySensor.reset();
    } else {
        inainte();
    }
}
