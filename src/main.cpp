/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       wangzilong                                                */
/*    Created:      Tue Jul 28 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotor1           motor         1               
// LeftMotor2           motor         2               
// RightMotor1          motor         3               
// RightMotor2          motor         4               
// LeftIntake           motor         5               
// RightIntake          motor         6               
// FrontRoller          motor         7               
// RearRoller           motor         8      
// Vision               vision        9         
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "MotorControl.h"

using namespace vex;



vex::competition Competition;

event checkRed = event();
event checkBlue = event();
event checkGreen = event();

void pre_auton( void ) {
// All activities that occur before the competition starts
// Example: clearing encoders, setting servo positions, ...

}

void autonomous( void ) {

}

void usercontrol ( void ) {
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
    Competition.drivercontrol( usercontrol );
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
        vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
}