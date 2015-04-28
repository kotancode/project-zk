#ifndef DriveTrain_h
#define DriveTrain_h

#include "application.h"
#include "RoboClaw.h"

class DriveTrain
{
public:
    DriveTrain(Stream *serialBus);
    bool begin();
    bool allForward(uint8_t speed);
    bool allStop();
    bool allTurnLeft(uint8_t speed);
    bool allTurnRight(uint8_t speed);
    bool allBackward(uint8_t speed);

private:
    Stream *serial;
    RoboClaw *frontController;
    RoboClaw *rearController;
};

#endif
