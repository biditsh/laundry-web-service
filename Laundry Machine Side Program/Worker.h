/* Interface module for multithreaded server thread class
   RAB 5/2/16 */
#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include <atomic>
#include "Socket.h"

using namespace std;

/** data structure for managing control of the server */
struct ControlData {
  /** continue serving while contin is non-zero.
      The type atomic<int> prevents "race condition" errors if multiple
      threads try to access contin at the same time */
  atomic<int> contin;

  /** default constructor
      @sc assign 1 to contin */
  ControlData() { contin = 1; }
};

/** States for a Worker object */
enum ThreadState { RUNNING, DONE };

/** A class representing a thread that implements services for a client */
class Worker : public thread {
protected:
  int id;            /**< unique identifier for this worker thread */
  Socket *sockp;     /**< socket for communicating with client */
  ThreadState state; /**< current status of this worker thread */
  // static int MAXBUFF; /**< buffer size for socket communication */
  char MachineId[13]; /**this is the Id of machine that's connected */

public:
  /** @param i ID number for this worker thread
      @param sp Pointer to socket for communicating with client */
  Worker(int i = -1, Socket *sp = 0, const ControlData *cdp = 0,
         const char Id[13] = "try-12-123-l");

  ~Worker();
  ThreadState getState() {
    return state;
    cout << "y.1" << endl;
  }
  int getId() {
    return id;
    cout << "y.2" << endl;
  }

protected:
  /** @param cdp Points to shared data structure for controlling server */
  void doWork(const ControlData *cdp);
};

#endif