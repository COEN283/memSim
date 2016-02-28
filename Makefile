CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra -std=c++11 

ALLOCATION=allocation.cpp allocation.h
calculon=calculon.cpp calculon.h

all: allocation.o calculon.o 
	$(CPC) $(CFLAGS) memSim.cpp allocation.o calculon.o -o memSim

allocation.o: $(ALLOCATION)
	$(CPC) $(CFLAGS) -c allocation.cpp  -o allocation.o 

calculon.o: $(ALLOCATION) $(calculon)
	$(CPC) $(CFLAGS) -c calculon.cpp  -o calculon.o 


clean:
	rm *.o &> /dev/null; rm memSim &> /dev/null
