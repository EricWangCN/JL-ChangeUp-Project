#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotor1 = motor(PORT11, ratio18_1, false);
motor LeftMotor2 = motor(PORT17, ratio18_1, true);
motor RightMotor1 = motor(PORT15, ratio18_1, true);
motor RightMotor2 = motor(PORT16, ratio18_1, false);
motor LeftIntake = motor(PORT20, ratio18_1, false);
motor RightIntake = motor(PORT14, ratio18_1, true);
motor FrontRoller = motor(PORT12, ratio18_1, false);
motor RearRoller = motor(PORT21, ratio18_1, false);
signature Vision5__BLUEBOX =
    signature(1, -3441, -2785, -3113, 8975, 10355, 9665, 2.5, 0);
signature Vision5__GREENBOX =
    signature(2, -5767, -4965, -5366, -3803, -2861, -3332, 2.5, 0);
signature Vision5__REDBOX =
    signature(3, 8099, 8893, 8496, -1505, -949, -1227, 2.5, 0);
signature Vision5__SIG_4 = signature(4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision5__SIG_5 = signature(5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision5__SIG_6 = signature(6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision5__SIG_7 = signature(7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision =
    vision(PORT9, 50, Vision5__BLUEBOX, Vision5__GREENBOX, Vision5__REDBOX,
           Vision5__SIG_4, Vision5__SIG_5, Vision5__SIG_6, Vision5__SIG_7);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}