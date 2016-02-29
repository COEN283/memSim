/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "bestFit.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
BestFit::BestFit(int start, int size, int finish):
Allocation(start, size, finish)
{}

BestFit::~BestFit()
{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool BestFit::allocate()
{
	int pos;
	int bestPos = -1;
	int bestFreeSize = MEM_SIZE;
	int freeSize = 0;

	// loop through memory
	for(int i = 0; i < MEM_SIZE; i++)
	{
		// if memory is empty
		if(!memory[i])
		{
			// check if freeSize has already been incremented
			if(!freeSize)
			{
				// if not, then start of new free block
				// store pos
				pos = i;
			}

			// increment freeSize
			freeSize++;	
		}
		// if the memory location is not empty
		// check if freeSize is > 0
		// if freeSize > 0, then end of free block
		else if(freeSize)
		{
			// check if free size >= needed size
			if(freeSize >= allocationSize)
			{
				// check if it's better than current best freeSize
				if((freeSize - allocationSize) < bestFreeSize)
				{
					// store new best freeSize
					bestPos = pos;
					bestFreeSize = freeSize;
				}
			}
			
			// set freeSize to 0
			freeSize = 0;
		}
	}

	// checks if allocation was possible
	if(bestPos >= 0)
	{
		// set memory position to best free size start position
		memPos = bestPos;

		// mark memory as occupied
		for(int i = bestPos; i < allocationSize; i++)
		{
			memory[i] = true;
		}

		amountAllocated += allocationSize;
		
		// return successfully allocated memory
		return true;
	}
	// if not, return failure
	else
	{
		return false;
	}
}

bool BestFit::deallocate()
{
	for(int i = memPos; i < allocationSize; i++)
		memory[i] = false;

	amountAllocated -= allocationSize;

	return true;
}

int BestFit::getFragments()
{
	int numFragments = 0;

	// loop through array
	for(int i = 0; i < MEM_SIZE; i++)
	{
		// if memory slot is empty
		if(!memory[i])
		{
			// check if i == 0
			if(!i)
			{
				// if i == 0, we started off with empty fragment
				// increment fragment
				numFragments++;
			}
			else
			{
				// if i != 0, check if previous memory slot is free
				if(memory[i - 1])
				{
					// if previous slot is occupied, begin new fragment
					numFragments++;
				}
			}
		}
	}

	// return fragment
	return numFragments;
}

int BestFit::getFreeMem()
{
	return MEM_SIZE - amountAllocated;
}
