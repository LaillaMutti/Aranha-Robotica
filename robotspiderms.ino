#define BLYNK_TEMPLATE_ID "TMPL2f9GsKJDy"
#define BLYNK_TEMPLATE_NAME "ROBOT SPIDER"
#define BLYNK_AUTH_TOKEN "Yl1FdAvkFzRyT-Z_c7P1MptmrpHzOYjQ"
#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Adafruit_PWMServoDriver.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial

char ssid[] = "lailla";
char pass[] = "12345678";
char auth[] = "Yl1FdAvkFzRyT-Z_c7P1MptmrpHzOYjQ";

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

bool apertado = false;

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

int angleToPulse(int angulo) {
  return map(angulo, 0, 180, 150, 600);
}

BLYNK_WRITE(V0) {
  apertado = param.asInt();
}

void andar() {
  // Perna 1
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(c1, 0, angleToPulse(90));
  delay(150);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(q1, 0, angleToPulse(90));
  delay(300);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(c1, 0, angleToPulse(130));
  delay(300);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(q1, 0, angleToPulse(45));
  delay(300);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(c1, 0, angleToPulse(90));
  delay(150);
}
  /*Perna 2
  if (!apertado) return;
  pwm.setPWM(c2, 0, angleToPulse(90));
  delay(300);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(q2, 0, angleToPulse(90));
  delay(300);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(c2, 0, angleToPulse(40));
  delay(300);
  Blynk.run();
  if (!apertado) return;
  pwm.setPWM(q2, 0, angleToPulse(135));
  delay(300);
  Blynk.run();
}*/

void setup() {
  Serial.begin(115200);
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(60);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  if (apertado) {
    andar();
  }
}
