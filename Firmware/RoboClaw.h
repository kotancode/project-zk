#ifndef RoboClaw_h
#define RoboClaw_h

#include <stdint.h>
#include "application.h"

#define ROBOCLAW_FORWARD_M1         0
#define ROBOCLAW_BACKWARD_M1        1
#define ROBOCLAW_SET_MIN_MAIN_VOLTS 2
#define ROBOCLAW_SET_MAX_MAIN_VOLTS 3
#define ROBOCLAW_FORWARD_M2         4
#define ROBOCLAW_BACKWARD_M2        5
#define ROBOCLAW_DRIVE_M1           6           // forward, neutral, reverse all in range 0-127. HALF range of forward or reverse M1.
#define ROBOCLAW_DRIVE_M2           7           // same deal, but for motor 2.

// MIX MODE

#define ROBOCLAW_FORWARD            8
#define ROBOCLAW_BACKWARD           9
#define ROBOCLAW_TURN_RIGHT         10          // 0 - stop turn, 127 - full speed
#define ROBOCLAW_TURN_LEFT          11          // 0 - stop turn, 127 - full speed
#define ROBOCLAW_FWD_OR_BACK_7BIT   12
#define ROBOCLAW_LEFT_OR_RIGHT_7BIT 13


class RoboClaw
{
private:
    uint8_t     address;
    Stream *serial;
    bool writecommand(uint8_t address, uint8_t command, uint8_t value);

public:
    RoboClaw(uint8_t address, Stream *serialBus);

    bool allForward(uint8_t speed);
    bool stop();
    bool allBackward(uint8_t speed);
    bool turnLeft(uint8_t speed);
    bool turnRight(uint8_t speed);
};

#endif
