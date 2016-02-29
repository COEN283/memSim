CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra -std=c++11 

ALLOCATION=allocation.cpp allocation.h
CALCULON=calculon.cpp calculon.h
BESTFIT=bestFit.cpp bestFit.h
FIRSTFIT=firstFit.cpp firstFit.h
WORSTFIT=worstFit.cpp worstFit.h

all: allocation.o calculon.o bestFit.o firstFit.o worstFit.o 
	$(CPC) $(CFLAGS) memSim.cpp allocation.o calculon.o bestFit.o -o memSim

allocation.o: $(ALLOCATION)
	$(CPC) $(CFLAGS) -c allocation.cpp  -o allocation.o 

calculon.o: $(ALLOCATION) $(CALCULON)
	$(CPC) $(CFLAGS) -c calculon.cpp  -o calculon.o 

bestFit.o: $(ALLOCATION) $(BESTFIT)
	$(CPC) $(CFLAGS) -c bestFit.cpp  -o bestFit.o 

firstFit.o: $(ALLOCATION) $(BESTFIT)
	$(CPC) $(CFLAGS) -c firstFit.cpp  -o firstFit.o 

worstFit.o: $(ALLOCATION) $(BESTFIT)
	$(CPC) $(CFLAGS) -c worstFit.cpp  -o worstFit.o 


clean:
	rm *.o &> /dev/null; rm memSim &> /dev/null
