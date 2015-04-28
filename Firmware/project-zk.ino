// This #include statement was automatically added by the Spark IDE.
#include "RoboClaw.h"
#include "DriveTrain.h"

DriveTrain driveTrain(&Serial1);

void setup() {
     Serial.println("Setting up the core.");

     Spark.function("allForward", allForward);
     Spark.function("allStop", allStop);
     Spark.function("simplecmd", simpleCommand);

     Serial.begin(38400);
     Serial1.begin(38400);
     driveTrain.begin();
    // Serial1.begin(38400);
}

void loop() {
    delay(5000);
    Serial.println("Still alive.");
}

String getValue(String data, char separator, int index)
{
 int found = 0;
  int strIndex[] = {
0, -1  };
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
  if(data.charAt(i)==separator || i==maxIndex){
  found++;
  strIndex[0] = strIndex[1]+1;
  strIndex[1] = (i == maxIndex) ? i+1 : i;
  }
 }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

int allForward(String command)
{
    uint8_t speed = command.toInt();
    driveTrain.allForward(speed);
    return 1;
}

int allStop(String command)
{
    driveTrain.allStop();
    return 1;
}

// COMMAND:VALUE:VALUE
int simpleCommand(String command)
{
  String commandCode = getValue(command, ':', 0);
  String commandValue = getValue(command, ':', 1);
  int speed = commandValue.toInt();
  if (commandCode.equals("LEFTTURN"))
  {
    driveTrain.allTurnLeft(speed);
  } else if (commandCode.equals("RIGHTTURN")) {
    driveTrain.allTurnRight(speed);
  }
}
