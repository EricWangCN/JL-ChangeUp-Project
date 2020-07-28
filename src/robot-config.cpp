#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotor1 = motor(PORT1, ratio18_1, false);
motor LeftMotor2 = motor(PORT2, ratio18_1, false);
motor RightMotor1 = motor(PORT3, ratio18_1, false);
motor RightMotor2 = motor(PORT4, ratio18_1, false);
motor LeftIntake = motor(PORT5, ratio18_1, false);
motor RightIntake = motor(PORT6, ratio18_1, false);
motor FrontRoller = motor(PORT7, ratio18_1, false);
motor RearRoller = motor(PORT8, ratio18_1, false);

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