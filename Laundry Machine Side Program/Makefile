# Makefile for socket and examples

CXX = g++
#CXX = clang++
CXXFLAGS = -Wall -std=c++11 -Wextra -Wshadow -Wpedantic #-mcpu=cortex-a8 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_{1,2,4,8}

all: Worker.o PiClasses.o Socket.o pro4


pro4: pro4.o PiClasses.o $(SERVER_OBJS) Worker.o Socket.o
	$(CXX) $(CXXFLAGS) -pthread -o pro4 pro4.o PiClasses.o Socket.o Worker.o

pro4.o: pro4.cpp PiClasses.o 
	$(CXX) $(CXXFLAGS) -c pro4.cpp

Worker.o: Worker.h Worker.cpp
	$(CXX) $(CXXFLAGS) -c Worker.cpp

PiClasses.o: PiClasses.cpp PiClasses.h
	$(CXX) $(CXXFLAGS) -c PiClasses.cpp

Socket.o:  Socket.cpp Socket.h
	$(CXX) $(CXXFLAGS) -c Socket.cpp


SERVER_OBJS = server.o Socket.o Worker.o

clean:
	rm -f *.o pro4

