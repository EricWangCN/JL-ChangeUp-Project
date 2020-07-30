#include "robot-config.h"
/*
 * @func: move
 * @para: leftSpeed: speed of left side of the chassis, its range is [-100, 100].
 * @para: rightSpeed: speed of right side of the chassis, its range is [-100, 100].
 * @author: ZilongWang, wangzilong@bjtu.edu.cn
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
 * @author: ZilongWang, wangzilong@bjtu.edu.cn
 *
 * Using percent to control intake.
 */
void intake(float speed) {
    LeftIntake.spin(forward, speed, pct);
    RightIntake.spin(forward, speed, pct);
}

/*
 * @func: rearRoller
 * @para: speed: speed of rear roller, its range is [-100, 100].
 * @author: ZilongWang, wangzilong@bjtu.edu.cn
 *
 * Using percent to control rear roller.
 */
void rearRoller(float speed) {
    if(speed != 0)
        RearRoller.spin(forward, speed, pct);
    else
        RearRoller.stop(hold);
}

/*
 * @func: frontRoller
 * @para: speed: speed of front roller, its range is [-100, 100].
 * @author: ZilongWang, wangzilong@bjtu.edu.cn
 *
 * Using percent to control front roller.
 */
void frontRoller(float speed) {
    FrontRoller.spin(forward, speed, pct);
}