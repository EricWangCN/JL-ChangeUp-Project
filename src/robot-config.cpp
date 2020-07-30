#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotor1 = motor(PORT11, ratio18_1, false);
motor LeftMotor2 = motor(PORT17, ratio18_1, true);
motor RightMotor1 = motor(PORT15, ratio18_1, true);
motor RightMotor2 = motor(PORT16, ratio18_1, false);
motor LeftIntake = motor(PORT20, ratio18_1, false);
motor RightIntake = motor(PORT14, ratio18_1, false);
motor FrontRoller = motor(PORT12, ratio18_1, false);
motor RearRoller = motor(PORT21, ratio18_1, false);
/*vex-vision-config:begin*/
signature Vision1__BLUEBALL = signature (1, -3135, -2185, -2660, 7999, 12061, 10030, 2.5, 0);
signature Vision1__REDBALL = signature (2, 5835, 8949, 7392, -1, 811, 405, 2.5, 0);
vision Vision1 = vision (PORT1, 50, Vision1__BLUEBALL, Vision1__REDBALL);
/*vex-vision-config:end*/
controller Controller1 = controller(primary);
line Line1 = line(Brain.ThreeWirePort.A);
line Line2 = line(Brain.ThreeWirePort.B);

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