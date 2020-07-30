// Author: Zilong Wang
// Email : wangzilong@bjtu.edu.cn
// Date  : 2020-07-30
#include <queue>
#include "robot-config.h"
#include "MotorControl.h"
#include <cmath>

#define HAVE_BALL 50
#define DELTA_X 100

extern std::string Alliance;

//Declare a class called Ball.
class Ball {
private:
    bool isExist = false;
    std::string ballType;
public:
    ~Ball(); // Destructor of class Ball
    Ball(bool isExist, std::string ballType) { // Constructor of class Ball
        isExist = false;
        ballType = "void";
    }
    Ball(Ball *b) { // Constructor of class Ball with parameter whose type is class Ball
        this->isExist = b->getExist();
        this->ballType = b->getBallType();
    }
    bool getExist() { // Get existance
        return isExist;
    }
    std::string getBallType() { // Get the color of a ball ("blue" "red" "void")
        return ballType;
    }
    void changeBallStatus(bool isExist, std::string ballType) { // Change info of a ball
        this->isExist = isExist;
        this->ballType = ballType;
    }
};

int IntakeControlTask() {
    Ball B1 = Ball(false, "void"), B2 = Ball(false, "void"), B3 = Ball(false, "void"), B4 = Ball(false, "void");
    // Declaration of two ball paths using STL queue.
    std::queue<Ball> path1;
    std::queue<Ball> path2;
    // Declaration of the coordinate of the ball
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
                if (!flagBlue || std::abs(blueX1 - lastBlueX1) > DELTA_X) path1.push(B4);
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
                if (!flagRed || std::abs(lastRedX1 - redX1) > DELTA_X) path1.push(B4);
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
                        B2 = Ball(B3);
                        task::sleep(200);
                    } else {
                        rearRoller(0);
                    }
                } else {
                    if (path2.empty()) {
                        if (path1.size() < 2) {
                            frontRoller(0);
                            if (!Controller1.ButtonR1.pressing()) rearRoller(0);
                        } else {
                            frontRoller(100);
                            rearRoller(-100);
                            path1.pop();
                            task::sleep(300);
                        }
                    } else {
                        frontRoller(100);
                        rearRoller(-1);
                        path1.pop();
                        task::sleep(300);
                    }
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

        if (Controller1.ButtonR1.pressing()) {
            rearRoller(100);
            if (Line2.value(percent) < HAVE_BALL) {
                task::sleep(300);
                path2.pop();
            }
        }
        task::sleep(30);
    }
}