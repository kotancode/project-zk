#include "DriveTrain.h"

DriveTrain::DriveTrain(Stream *serialBus)
{
    serial = serialBus;
    frontController = new RoboClaw(0x80, serialBus);
    rearController = new RoboClaw(0x81, serialBus);
}

bool DriveTrain::begin()
{
    return true;
}

bool DriveTrain::allForward(uint8_t speed) {
    frontController->allForward(speed);
    rearController->allForward(speed);
    return true;
}

bool DriveTrain::allStop()
{
    frontController->stop();
    rearController->stop();
}

bool DriveTrain::allTurnLeft(uint8_t speed)
{
  frontController->turnLeft(speed);
  rearController->turnRight(speed); // M1 and M2 are reversed for rear controller
}

bool DriveTrain::allTurnRight(uint8_t speed)
{  
  frontController->turnRight(speed);
  rearController->turnLeft(speed); // M1 and M2 are reversed for rear controller
}

bool DriveTrain::allBackward(uint8_t speed)
{
  frontController->allBackward(speed);
  rearController->allBackward(speed);
}
