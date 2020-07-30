#include <queue>
#include "robot-config.h"
#include "MotorControl.h"

#define HAVE_BALL 50

extern std::string Alliance;

class Ball {
private:
    bool isExist = false;
    std::string ballType;
public:
    ~Ball();
    Ball(bool isExist, std::string ballType) {
        isExist = false;
        ballType = "void";
    }
    Ball(Ball *b) {
        this->isExist = b->getExist();
        this->ballType = b->getBallType();
    }
    bool getExist() {
        return isExist;
    }
    std::string getBallType() {
        return ballType;
    }
    void changeBallStatus(bool isExist, std::string ballType) {
        this->isExist = isExist;
        this->ballType = ballType;
    }
};

int IntakeControlTask() {
    Ball B1 = Ball(false, "void"), B2 = Ball(false, "void"), B3 = Ball(false, "void"), B4 = Ball(false, "void");
    std::queue<Ball> path1;
    std::queue<Ball> path2;
    int blueX1, blueY1, redX1, redY1;
    int lastBlueX1, lastBlueY1, lastRedX1, lastRedY1;
    bool flagBlue = false, flagRed = false;
    Vision1.takeSnapshot(Vision1__BLUEBALL);
    blueX1 = Vision1.largestObject.centerX;
    blueY1 = Vision1.largestObject.centerY;

    Vision1.takeSnapshot(Vision1__REDBALL);
    redX1 = Vision1.largestObject.centerX;
    redY1 = Vision1.largestObject.centerY;

    while (true) {
        if (Controller1.ButtonL1.pressing()) {
            Vision1.takeSnapshot(Vision1__BLUEBALL);
            if (Vision1.largestObject.exists) {
                lastBlueX1 = blueX1;
                lastBlueY1 = blueY1;
                blueX1 = Vision1.largestObject.centerX;
                blueY1 = Vision1.largestObject.centerY;
                B4.changeBallStatus(true, "blue");
                if (!flagBlue) path1.push(B4);
                flagBlue = true;
            } else {
                B3 = Ball(B4);
                B4.changeBallStatus(false, "void");
                flagBlue = false;
            }
            
            Vision1.takeSnapshot(Vision1__REDBALL);
            if (Vision1.largestObject.exists) {
                lastRedX1 = redX1;
                lastRedY1 = redY1;
                redX1 = Vision1.largestObject.centerX;
                redY1 = Vision1.largestObject.centerY;
                B4.changeBallStatus(true, "red");
                if (!flagRed) path1.push(B4);
                flagRed = true;
            } else {
                B3 = Ball(B4);
                B4.changeBallStatus(false, "void");
                flagRed = false;
            }

            if (Line1.value(percent) < HAVE_BALL) {
                if (path1.front().getBallType() == Alliance) {
                    if (path2.empty()) {
                        rearRoller(100);
                        frontRoller(100);
                        path2.push(path1.front());
                        path1.pop();
                        task::sleep(200);
                    } else {
                        rearRoller(0);
                    }
                } else {

                }
            } else {
                frontRoller(100);
            }
            intake(100);
        } else if (Controller1.ButtonL2.pressing()) {
            intake(-100);
            frontRoller(-100);
        } else {
            frontRoller(0);
            if (!Controller1.ButtonR1.pressing()) rearRoller(0);
            intake(0);
        }
        task::sleep(30);
    }
}
