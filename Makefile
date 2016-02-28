CC=gcc
CPC=g++

CFLAGS=-g -Wall -Wextra -std=c++11 

ALLOCATION=allocation.cpp allocation.h
ALTRON=altron.cpp altron.h

all: allocation.o altron.o 
	$(CPC) $(CFLAGS) memSim.cpp allocation.o altron.o -o memSim

allocation.o: $(ALLOCATION)
	$(CPC) $(CFLAGS) -c allocation.cpp  -o allocation.o 

altron.o: $(ALLOCATION) $(ALTRON)
	$(CPC) $(CFLAGS) -c altron.cpp  -o altron.o 


clean:
	rm *.o &> /dev/null; rm memSim &> /dev/null
