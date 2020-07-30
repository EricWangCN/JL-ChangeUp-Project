using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor LeftMotor1;
extern motor LeftMotor2;
extern motor RightMotor1;
extern motor RightMotor2;
extern motor LeftIntake;
extern motor RightIntake;
extern motor FrontRoller;
extern motor RearRoller;
extern signature Vision1__BLUEBALL;
extern signature Vision1__REDBALL;
extern signature Vision1__SIG_3;
extern signature Vision1__SIG_4;
extern signature Vision1__SIG_5;
extern signature Vision1__SIG_6;
extern signature Vision1__SIG_7;
extern vision Vision1;
extern controller Controller1;
extern line Line1;
extern line Line2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );