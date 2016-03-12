/*
 * nextFit.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Sisi Yang
 *    IDE Used: Eclipse Luna 4.4.0 for C++ (Mac OSX El Capitan version 10.11.2)
 *    
 */
//This program is created for COEN283 project.

#include "nextFit.h"

//static variable initialization
int NextFit::memArr[MEM_SIZE] = {0};
int NextFit::allocatedMem = 0;
int NextFit::currIndex = 0;

//constructor
NextFit::NextFit(int start, int size, int finish)
: Allocation(start, size, finish) {}

//destructor
NextFit::~NextFit() {}

//member functions
bool NextFit::allocate()
{
	//keep track of size of empty memory
	int count = 0;

	for(int i = 0; i < MEM_SIZE; i++)
	{
		//if memory slot is empty, start counting
		if(memArr[currIndex] == 0)
			count++;
		//if memory slot is occupied, reset counter
		else
			count = 0;

		//if counter is enough for the allocation object
		if(count >= allocationSize)
		{
			//update memory location
			memLoc = currIndex - count + 1;

			//update memArr, mark occupied indexes as 1
			for(int j = 0; j < allocationSize; j++)
				memArr[memLoc + j] = 1;

			//update allocatedMem
			allocatedMem += allocationSize;

			return true;
		}

    currIndex++;
    currIndex %= MEM_SIZE;

	}//ends for loop

	//if no memory chunk is big enough to fit the allocation object
	return false;

}//ends allocate()

bool NextFit::deallocate()
{
	//starting at the memory location of the allocation object
	for(int i = 0; i < allocationSize; i++)
	{
		//indicate empty memory by setting memory slots to 0
		memArr[memLoc + i] = 0;

	}//ends for loop

	allocatedMem -= allocationSize;
	
	return true;

}//ends deallocate()

int NextFit::getFragments()
{
	//keeps track of number of memory fragments
	int count = 0;

	//loop through memory
	for(int i = 0; i < MEM_SIZE; i++)
	{
		//if memory slot is empty and index is 0
		if(memArr[i] == 0 && i == 0)
			count++; //increment counter

		//else if the memory slot is empty and the previous slot is occupied
		else if(memArr[i] == 0 && memArr[i - 1] == 1)
			count++; //increment counter

	}//ends for loop

	return count;

}//ends getFragments()

int NextFit::getFreeMem()
{
	return MEM_SIZE - allocatedMem;

}//ends getFreeMem

