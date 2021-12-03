p1: a4.1.cpp
	g++ -Wall -o p1 a4.1.cpp

all: p1
	./p1

clean:
	rm *.o p1 