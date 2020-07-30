using namespace vex;

using signature = vision::signature;
using code = vision::code;

extern brain Brain;


// VEXcode devices
extern controller Controller1;
extern motor LeftMotor1;
extern motor LeftMotor2;
extern motor RightMotor1;
extern motor RightMotor2;
extern motor LeftIntake;
extern motor RightIntake;
extern motor FrontRoller;
extern motor RearRoller;
extern signature Vision5__BLUEBOX;
extern signature Vision5__GREENBOX;
extern signature Vision5__REDBOX;;
extern signature Vision5__SIG_4;
extern signature Vision5__SIG_5;
extern signature Vision5__SIG_6;
extern signature Vision5__SIG_7;
extern vision Vision;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );