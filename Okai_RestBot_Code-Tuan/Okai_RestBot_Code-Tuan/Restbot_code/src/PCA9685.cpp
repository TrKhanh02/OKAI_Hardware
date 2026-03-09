#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include "PCA9685.h"

// Khởi tạo đối tượng PWM
Adafruit_PWMServoDriver PWM = Adafruit_PWMServoDriver(0x40);

int currentVelocity = 100;

void servo_reset(int port)
{
  PWM.setPWM(port, 0, 102);
}

void servo_port(int port, int goc_bandau, int goc_ketthuc)
{
  int goc_bandau_fix = map(goc_bandau, 0, 180, 102, 623);
  int goc_ketthuc_fix = map(goc_ketthuc, 0, 180, 102, 623);
  PWM.setPWM(port, 0, goc_bandau_fix);
  PWM.setPWM(port, 0, goc_ketthuc_fix);
}

void move_forward_motor(int move_port, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port, 0, pwmValue);
  PWM.setPWM(move_port + 1, 0, 0);
}

void move_backward_motor(int move_port, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port + 1, 0, pwmValue);
  PWM.setPWM(move_port, 0, 0);
}

void move_backward_motor_double(int move_port1, int move_port2, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port1 + 1, 0, pwmValue);
  PWM.setPWM(move_port1, 0, 0);
  PWM.setPWM(move_port2 + 1, 0, pwmValue);
  PWM.setPWM(move_port2, 0, 0);
}

void move_forward_motor_double(int move_port1, int move_port2, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port1, 0, pwmValue);
  PWM.setPWM(move_port1 + 1, 0, 0);
  PWM.setPWM(move_port2, 0, pwmValue);
  PWM.setPWM(move_port2 + 1, 0, 0);
}

void move_right_motor(int move_port1, int move_port2, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port1, 0, pwmValue);
  PWM.setPWM(move_port1 + 1, 0, 0);
  PWM.setPWM(move_port2 + 1, 0, 0);
  PWM.setPWM(move_port2, 0, 0);
}

void move_right_motor_backward(int move_port1, int move_port2, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port1, 0, 0);
  PWM.setPWM(move_port1 + 1, 0, pwmValue);
  PWM.setPWM(move_port2, 0, 0);
  PWM.setPWM(move_port2 + 1, 0, pwmValue);
}
void move_left_motor_backward(int move_port1, int move_port2, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port1, 0, 0);
  PWM.setPWM(move_port1 + 1, 0, 0);
  PWM.setPWM(move_port2, 0, 0);
  PWM.setPWM(move_port2 + 1, 0, pwmValue); // Quay ngược
}

void move_sideways(int move_port1, int move_port2, int SPEED, bool direction_right)
{
  SPEED = constrain(SPEED, 0, 100);
  int pwmValue = (SPEED * 4095) / 100;
  if (direction_right)
  {
    PWM.setPWM(move_port1, 0, pwmValue);
    PWM.setPWM(move_port1 + 1, 0, 0);
    PWM.setPWM(move_port2 + 1, 0, pwmValue);
    PWM.setPWM(move_port2, 0, 0);
  }
  else
  {
    PWM.setPWM(move_port1 + 1, 0, pwmValue);
    PWM.setPWM(move_port1, 0, 0);
    PWM.setPWM(move_port2, 0, pwmValue);
    PWM.setPWM(move_port2 + 1, 0, 0);
  }
}
void move_left_motor(int move_port1, int move_port2, int SPEED)
{
  SPEED = SPEED * 2.55;
  uint16_t pwmValue = (SPEED * 4095 / 255);
  PWM.setPWM(move_port1 + 1, 0, 0);
  PWM.setPWM(move_port1, 0, 0);
  PWM.setPWM(move_port2 + 1, 0, 0);
  PWM.setPWM(move_port2, 0, pwmValue);
}

void PWM_BEGIN()
{
  PWM.begin();
  PWM.setOscillatorFrequency(27000000);
  PWM.setPWMFreq(60);
}

void SR04_BEGIN(int trig, int echo)
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void stopAll(int move_port1, int move_port2)
{
  PWM.setPWM(move_port1, 0, 0);
  PWM.setPWM(move_port2, 0, 0);
}

// Hàm mới: Set velocity()% for all
void setVelocity(int velocity)
{
  if (velocity >= 0 && velocity <= 100)
  {
    currentVelocity = velocity;
  }
}

// Hàm mới: Lấy tốc độ hiện tại
int getCurrentVelocity()
{
  return currentVelocity;
}