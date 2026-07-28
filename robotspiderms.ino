#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angleToPulse(int angulo) {
  int pulsoMin = 150;   // 0°
  int pulsoMax = 600;   // 180°
  return map(angulo, 0, 180, pulsoMin, pulsoMax);
}

int q1 = 0;
int q2 = 1;
int q3 = 2;
int q4 = 3;
int c1 = 4;
int c2 = 5;
int c3 = 6;
int c4 = 7;
int p1 = 8;
int p2 = 9;
int p3 = 10;
int p4 = 11;
void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(60);
  
  Serial.println("Teste dos quadris iniciado...");
}

void loop() { //testando o movimento FRENTE para a perna esquerda frontal
  pwm.setPWM(q1, 0, angleToPulse(45));
  delay(800);
  pwm.setPWM(c1, 0, angleToPulse(90));
  delay(800);
  pwm.setPWM(q1, 0, angleToPulse(90));
  delay(800);
  pwm.setPWM(c1, 0, angleToPulse(135));
  delay(800);
}

void desligada(){
  pwm.setPWM(q1, 0, angleToPulse(90));
  delay(500);
  pwm.setPWM(q2, 0, angleToPulse(90));
  delay(500);
  pwm.setPWM(q3, 0, angleToPulse(90));
  delay(500);
  pwm.setPWM(q4, 0, angleToPulse(90));
  delay(1000);
  pwm.setPWM(c1, 0, angleToPulse(135));
  delay(1000);
  pwm.setPWM(c2, 0, angleToPulse(45));
  delay(1000);
  pwm.setPWM(c3, 0, angleToPulse(135));
  delay(1000);
  pwm.setPWM(c4, 0, angleToPulse(45));
  delay(1000);
}
