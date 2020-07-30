/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Zilong Wang                                               */
/*    Email:        wangzilong@bjtu.edu.cn                                    */
/*    Created:      Thu Jul 30 2020                                           */
/*    Description:  Jiaolong VRC Change Up Project                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor1           motor         11              
// LeftMotor2           motor         17              
// RightMotor1          motor         15              
// RightMotor2          motor         16              
// LeftIntake           motor         20              
// RightIntake          motor         14              
// FrontRoller          motor         12              
// RearRoller           motor         21              
// Vision1              vision        1               
// Controller1          controller                    
// Line1                line          A               
// Line2                line          B               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "BallsControl.h"

using namespace vex;
vex::competition Competition;

event checkRed = event();
event checkBlue = event();
event checkGreen = event();

std::string Alliance = "blue";

void pre_auton( void ) {

}

void autonomous( void ) {

}
void drivercontrol ( void ) {
    int C1,C3,L1,L2,R1,R2,lv,rv;
    while (true) {
        C3=Controller1.Axis3.position(vex::percentUnits::pct);
        C1=Controller1.Axis1.position(vex::percentUnits::pct);
        L1=Controller1.ButtonL1.pressing();
        L2=Controller1.ButtonL2.pressing();
        R1=Controller1.ButtonR1.pressing();
        R2=Controller1.ButtonR2.pressing();
        lv = C3 + C1;
        rv = C3 - C1;
        move(lv, rv);
        if (L1) {
            intake(100);
            frontRoller(100);
        } else if (L2) {
            intake(-100);
            frontRoller(-100);
        } else {
            intake(0);
            frontRoller(0);
        }

        if (R1) rearRoller(100);
        else if (R2) rearRoller(-100);
        else rearRoller(0);
    }
}

int main() {
    pre_auton();
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( drivercontrol );
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
        vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
}