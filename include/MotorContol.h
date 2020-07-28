#include "robot-config.h"
/*
 * @func: move
 * @para: leftSpeed: speed of left side of the chassis, its range is [-100, 100].
 * @para: rightSpeed: speed of right side of the chassis, its range is [-100, 100].
 * @author: ZilongWang ,wangzilong@bjtu.edu.cn
 *
 * Using voltage to control chassis.
 */
void move(float leftSpeed, float rightSpeed){
    LeftMotor1.spin(forward, leftSpeed * 130, vex::voltageUnits::mV);
    LeftMotor2.spin(forward, leftSpeed * 130, vex::voltageUnits::mV);
    RightMotor1.spin(forward, rightSpeed * 130, vex::voltageUnits::mV);
    RightMotor2.spin(forward, rightSpeed * 130, vex::voltageUnits::mV);
}

/*
 * @func: intake
 * @para: leftSpeed: speed of left side of the intake, its range is [-100, 100].
 * @para: rightSpeed: speed of right side of the intake, its range is [-100, 100].
 * @author: ZilongWang ,wangzilong@bjtu.edu.cn
 *
 * Using percent to control intake.
 */
 void intake(float leftSpeed, float rightSpeed) {
     LeftIntake.spin(forward, leftSpeed, pct);
     RightIntake.spin(forward, rightSpeed, pct);
 }

 void rearRoller(float speed) {
     RearRoller.spin(forward, speed, pct);
 }

 void frontRoller(float speed) {
      FrontRoller.spin(forward, speed, pct);
 }