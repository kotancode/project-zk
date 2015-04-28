#include "RoboClaw.h"

RoboClaw::RoboClaw(uint8_t deviceaddress, Stream *serialBus) {
    address = deviceaddress;
    serial = serialBus;
}

bool RoboClaw::writecommand(uint8_t address, uint8_t command, uint8_t value)
{
 /* Serial.println("About to write values: ");
  Serial.print(address);
  Serial.print(" ");
  Serial.print(command);
  Serial.print(" ");
  Serial.println(value); */

  uint8_t crc=0;

  crc += address;
  serial->write(address);
  crc += command;
  serial->write(command);
  crc += value;
  serial->write(value);
  serial->write(crc&0x7F);

  return true;
}

bool RoboClaw::allForward(uint8_t speed)
{
    writecommand(address, ROBOCLAW_FORWARD_M1, speed);
    writecommand(address, ROBOCLAW_FORWARD_M2, speed);
    return true;
}

bool RoboClaw::stop()
{
    writecommand(address, ROBOCLAW_FORWARD_M1, 0);
    writecommand(address, ROBOCLAW_FORWARD_M2, 0);
    return true;
}

bool RoboClaw::allBackward(uint8_t speed)
{
  writecommand(address, ROBOCLAW_BACKWARD_M1, speed);
  writecommand(address, ROBOCLAW_BACKWARD_M2, speed);
  return true;
}

// --- MIX MODE OPERATIONS ---
bool RoboClaw::turnLeft(uint8_t speed)
{
  writecommand(address, ROBOCLAW_TURN_LEFT, speed);
}

bool RoboClaw::turnRight(uint8_t speed)
{
  writecommand(address, ROBOCLAW_TURN_RIGHT, speed);
}
