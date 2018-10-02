
MenuDriver:  MenuDriver.o menu.o dorm.o floor.o machine.o helpers.o user.o
	g++ -g -Wall -std=c++11 -o MenuDriver MenuDriver.o menu.o dorm.o floor.o machine.o user.o

MenuDriver.o:  MenuDriver.cpp menu.o dorm.o floor.o machine.o user.o
	g++ -g -Wall -std=c++11 -c MenuDriver.cpp

user.o: user.cpp user.h
	g++ -g -Wall -std=c++11 -c user.cpp

menu.o:  menu.cpp menu.h
	g++ -g -Wall -std=c++11 -c menu.cpp

dorm.o: dorm.cpp dorm.h
	g++ -g -Wall -std=c++11 -c dorm.cpp

floor.o: floor.cpp floor.h
	g++ -g -Wall -std=c++11 -c floor.cpp

machine.o: machine.cpp machine.h
	g++ -g -Wall -std=c++11 -c machine.cpp
