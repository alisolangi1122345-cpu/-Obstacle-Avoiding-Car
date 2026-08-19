#include <Servo.h>

Servo servo;

// ---------- PINS ----------

// L298
const byte IN1 = 2;
const byte IN2 = 3;
const byte IN3 = 4;
const byte IN4 = 5;

// HC-SR04
const byte TRIG = 8;
const byte ECHO = 7;

// Servo
const byte SERVO = 9;

const int LIMIT = 20;


// ---------- SETUP ----------

void setup()
{
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  servo.attach(SERVO);

  servo.write(90);

  stopCar();

  delay(1000);
}


// ---------- DISTANCE ----------

long distanceCM()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  unsigned long time = pulseIn(ECHO, HIGH, 25000);

  if (time == 0)
    return 100;

  return time / 58;
}


// ---------- MOTORS ----------

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void stopCar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// ---------- SERVO SCAN ----------

long scanLeft()
{
  Serial.println("Scanning LEFT");

  servo.write(150);
  delay(800);

  long d = distanceCM();

  Serial.print("LEFT = ");
  Serial.println(d);

  return d;
}


long scanRight()
{
  Serial.println("Scanning RIGHT");

  servo.write(30);
  delay(800);

  long d = distanceCM();

  Serial.print("RIGHT = ");
  Serial.println(d);

  return d;
}


// ---------- MAIN ----------

void loop()
{
  // Sensor facing forward
  servo.write(90);
  delay(300);

  long front = distanceCM();

  Serial.print("FRONT = ");
  Serial.println(front);


  // -------- CLEAR --------

  if (front > LIMIT)
  {
    Serial.println("FORWARD");

    forward();

    delay(100);

    return;
  }


  // -------- OBSTACLE --------

  Serial.println("OBSTACLE!");

  stopCar();
  delay(300);


  // Scan left
  long leftDistance = scanLeft();

  delay(200);


  // Scan right
  long rightDistance = scanRight();

  delay(200);


  // Center
  servo.write(90);
  delay(300);


  // -------- DECISION --------

  if (leftDistance > rightDistance)
  {
    Serial.println("TURN LEFT");

    left();
    delay(600);
  }
  else
  {
    Serial.println("TURN RIGHT");

    right();
    delay(600);
  }

  stopCar();

  delay(200);
}