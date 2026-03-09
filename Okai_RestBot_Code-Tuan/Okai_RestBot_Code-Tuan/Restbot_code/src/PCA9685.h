#ifndef PCA9685_H
#define PCA9685_H

enum {
    port_servo_0 = 8,
    port_servo_1 = 9,
    port_servo_2 = 10,
    port_servo_3 = 11,
    port_servo_4 = 12,
    port_servo_5 = 13,
    port_servo_6 = 14,
    port_dc_motor_1_1 = 0,
    port_dc_motor_1_2 = 1,
    port_dc_motor_2_1 = 2,
    port_dc_motor_2_2 = 3,
    port_dc_motor_3_1 = 4,
    port_dc_motor_3_2 = 5,
    port_dc_motor_4_1 = 6,
    port_dc_motor_4_2 = 7,
};

void PWM_BEGIN();
void SR04_BEGIN(int trig, int echo);
void servo_reset(int port);
void move_right_motor_backward(int move_port1, int move_port2, int SPEED);
void move_left_motor_backward(int move_port1, int move_port2, int SPEED);
void move_sideways(int move_port1, int move_port2, int SPEED, bool direction_right);
void servo_port(int port, int goc_bandau, int goc_ketthuc);
void move_forward_motor(int move_port, int SPEED);
void move_backward_motor(int move_port, int SPEED);
void move_forward_motor_double(int move_port1, int move_port2, int SPEED);
void move_backward_motor_double(int move_port1, int move_port2, int SPEED);
void move_right_motor(int move_port1, int move_port2, int SPEED);
void move_left_motor(int move_port1, int move_port2, int SPEED);
void stopAll(int move_port1, int move_port2);
void setVelocity(int velocity);
int getCurrentVelocity();

#endif