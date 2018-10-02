#ifndef PICLASSES_H
#define PICLASSES_H

#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstring>
#include <sys/time.h>

using namespace std;


/**Machine class represents a machine to which the arduio and sensor is connected. Each laundry machine has one machine object.*/
class Machine {
  bool response;     /**boolean that says whether the sensor responded or non*/

public:
  /** Constructor, sets response to 0 (false) automatically*/
  Machine(void);
  /** tell whether sensor is responding or not
    @return returns true or false to tell if sensor has responded(is conected properly) or not*/
  bool IsResponding(void);
  /** set whether the sensor responded or not
  @param b is a boolean, true if sensor responds (or is connected)properly, false if it doesn't*/
  void setResponse(bool b);
  /** method to get the current time using standard library
  @return returns clock time as a double*/
  double getCurrentTime() {
    struct timeval tv = {0, 0};
    struct timezone tz;
    gettimeofday(&tv, &tz);
    return tv.tv_sec + tv.tv_usec / (double)1000000.;
  }
  /**change the status of machine in file as USED and update timer
@param time minute in timer sent as integer*/
  void setFileAsUSE(int time);
  /**change the status of machine in file as NOT USED*/
  void setFileAsNOTUSED(void);
  /**update the file with necessary error code if sensor isn't found or is unresponsive*/
  void setAsNoSensor(void);
};

/**inherited class of Machine class that deals with data from the sensor*/
class MovementData : public Machine {
  int x[2];   /**stores the values of movement on x- drection at that instant*/
  int y[2];   /**stores the values of movement on y- drection at that instant*/
  int z[2];   /**stores the values of movement on z- drection at that instant*/
  static int TESTTIME;  /**static int to store the time in seconds for reading data pattern*/

public:
  /**Constructor*/
  MovementData(void);
  /** method that checks the vibration pattern and analyzes it to decide if the machine's vibration is continuous
  @param reference to istream that represnts the address of serial port created by arduino*/
  bool contVibCheck(istream &file);
  static int CYCLEDURATION;  /**static int to store approximate time of funn laundry process in the macine*/
};

#endif