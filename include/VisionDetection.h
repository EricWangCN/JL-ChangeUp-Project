#include "robot-config.h"

bool isBlueBallExist() {
    Vision.takeSnapshot(Vision5__BLUEBOX);
    return Vision.objectCount > 0;
}

bool isRedBallExist() {
    Vision.takeSnapshot(Vision5__REDBOX);
    return Vision.objectCount > 0;
}