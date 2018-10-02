CXXFLAGS := -g -std=c++11 -Wall -Wextra -Wshadow -Wpedantic -Werror


CLIENTDriver: CLIENTDriver.o CLIENT.o Socket.o
	g++ $(CXXFLAGS) -o CLIENTDriver CLIENTDriver.o CLIENT.o Socket.o


CLIENTDriver.o: CLIENTDriver.cpp CLIENT.h Socket.o
	g++ $(CXXFLAGS) -c CLIENTDriver.cpp

CLIENT.o: CLIENT.cpp CLIENT.h Socket.o
	g++ $(CXXFLAGS) -c CLIENT.cpp


Socket.o: Socket.cpp Socket.h
	g++ $(CXXFLAGS) -c Socket.cpp

clean:
	rm -f *.o CLIENTDriver
