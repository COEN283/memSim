CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra -std=c++11 

ALLOCATION=allocation.cpp allocation.h
CALCULON=calculon.cpp calculon.h

all: allocation.o calculon.o bestFit.o 
	$(CPC) $(CFLAGS) memSim.cpp allocation.o calculon.o bestFit.o -o memSim

allocation.o: $(ALLOCATION)
	$(CPC) $(CFLAGS) -c allocation.cpp  -o allocation.o 

calculon.o: $(ALLOCATION) $(CALCULON)
	$(CPC) $(CFLAGS) -c calculon.cpp  -o calculon.o 

bestFit.o: $(ALLOCATION) $(BESTFIT)
	$(CPC) $(CFLAGS) -c bestFit.cpp  -o bestFit.o 


clean:
	rm *.o &> /dev/null; rm memSim &> /dev/null
