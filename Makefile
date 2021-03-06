CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra -std=c++11 

ALLOCATION=allocation.cpp allocation.h
CALCULON=calculon.cpp calculon.h
BESTFIT=bestFit.cpp bestFit.h
FIRSTFIT=firstFit.cpp firstFit.h
NEXTFIT=nextFit.cpp nextFit.h
WORSTFIT=worstFit.cpp worstFit.h
SIMPLE=simpleSegregated.cpp simpleSegregated.h
SEGREGATED=segregated.cpp segregated.h
BINARY=binaryBuddy.cpp binaryBuddy.h
DOUBLE=doubleBuddy.cpp doubleBuddy.h

all: allocation.o bestFit.o firstFit.o nextFit.o worstFit.o simple.o segregated.o binary.o double.o
	$(CPC) $(CFLAGS) memSim.cpp allocation.o calculon.h bestFit.o firstFit.o nextFit.o worstFit.o simple.o segregated.o binary.o double.o -o memSim

allocation.o: $(ALLOCATION)
	$(CPC) $(CFLAGS) -c allocation.cpp  -o allocation.o 

firstFit.o: $(ALLOCATION) $(FIRSTFIT)
	$(CPC) $(CFLAGS) -c firstFit.cpp  -o firstFit.o 

nextFit.o: $(ALLOCATION) $(NEXTFIT)
	$(CPC) $(CFLAGS) -c nextFit.cpp  -o nextFit.o 

bestFit.o: $(ALLOCATION) $(BESTFIT)
	$(CPC) $(CFLAGS) -c bestFit.cpp  -o bestFit.o 

worstFit.o: $(ALLOCATION) $(WORSTFIT)
	$(CPC) $(CFLAGS) -c worstFit.cpp  -o worstFit.o 

simple.o: $(ALLOCATION) $(SIMPLE)
	$(CPC) $(CFLAGS) -c simpleSegregated.cpp  -o simple.o 

segregated.o: $(ALLOCATION) $(SEGREGATED)
	$(CPC) $(CFLAGS) -c segregated.cpp  -o segregated.o 

binary.o: $(ALLOCATION) $(BINARY)
	$(CPC) $(CFLAGS) -c binaryBuddy.cpp  -o binary.o 

double.o: $(ALLOCATION) $(DOUBLE)
	$(CPC) $(CFLAGS) -c doubleBuddy.cpp  -o double.o 

clean:
	rm *.o &> /dev/null; rm memSim &> /dev/null
