using namespace vex;

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

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );