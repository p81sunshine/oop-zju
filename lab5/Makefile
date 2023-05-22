CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

all: main

main: fraction.o main.o
	$(CXX) $(CXXFLAGS) fraction.o main.o -o main

fraction.o: fraction.cpp fraction.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o

main.o: main.cpp fraction.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f fraction.o main.o main