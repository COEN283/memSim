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
bestFit::bestFit(unsigned int start, unsigned int size, unsigned int finish):
Allocation(start, size, finish)
{}

bestFit::~bestFit()
{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool bestFit::allocate()
{
	int pos;
	int bestPos = -1;
	unsigned int bestFreeSize = MEM_SIZE;
	unsigned int freeSize = 0;

	// loop through memory
	for(unsigned int i = 0; i < MEM_SIZE; i++)
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
		for(unsigned int i = bestPos; i < allocationSize; i++)
		{
			memory[i] = true;
		}

		// return successfully allocated memory
		return true;
	}
	// if not, return failure
	else
	{
		return false;
	}
}
