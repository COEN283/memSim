/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "worstFit.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
WorstFit::WorstFit(int start, int size, int finish):
Allocation(start, size, finish)
{}

WorstFit::~WorstFit()
{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool WorstFit::allocate()
{
	int pos;
	int worstPos = -1;
	int worstFreeSize = MEM_SIZE;
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
				// check if it's better than current worst freeSize
				if((freeSize - allocationSize) > worstFreeSize)
				{
					// store new worst freeSize
					worstPos = pos;
					worstFreeSize = freeSize;
				}
			}
			
			// set freeSize to 0
			freeSize = 0;
		}
	}

	// checks if allocation was possible
	if(worstPos >= 0)
	{
		// set memory position to worst free size start position
		memPos = worstPos;

		// mark memory as occupied
		for(int i = worstPos; i < allocationSize; i++)
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

bool WorstFit::deallocate()
{
	for(int i = memPos; i < allocationSize; i++)
		memory[i] = false;

	amountAllocated -= allocationSize;

	return true;
}

int WorstFit::getFragments()
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

int WorstFit::getFreeMem()
{
	return MEM_SIZE - amountAllocated;
}
