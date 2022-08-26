#include <Servo.h>

int cm = 0;
int triggerPin = 6;
int echoPin = 7;
int servoPort = 9;
int led1 = 10;
int led2 = 11;
int led3 = 12;  
Servo servo;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH);
}

void setup()
{
    Serial.begin(9600);
    servo.attach(servoPort);// ou usar (servoPort)em vez de 9 
  	pinMode(led1,OUTPUT);
  	pinMode(led2,OUTPUT);
  	pinMode(led3,OUTPUT);
  	
}

void loop()
{
    cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
    Serial.println(cm);
    if (cm <= 10)
    {
        servo.write(50);// função write configura em graus
      	digitalWrite(led1, HIGH);
      	delay(200);
        digitalWrite(led2, HIGH);
      	delay(200);
      	digitalWrite(led3, HIGH);
      	delay(200);
        digitalWrite(10, LOW);
      	delay(200);
      	digitalWrite(11, LOW);
      	delay(200);
      	digitalWrite(12, LOW);
      	delay(200);
      	
    }
    else
    {
        servo.write(0);
    }
    delay(300);
}