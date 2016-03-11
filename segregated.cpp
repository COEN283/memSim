/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <cmath>
#include "segregated.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************
//                                  0  1  2  3  4  5  6  7  8  9 
int Segregated::mem[MEM_MAX_SEG] = {6, 5, 4, 4, 4, 4, 4, 0, 0, 0};
int Segregated::numFragments = 0;
int Segregated::freeMem = MEM_SIZE;

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
Segregated::Segregated(int start, int size, int finish):
Allocation(start, size, finish)
{}

Segregated::~Segregated()

{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool Segregated::allocate()
{
	int index = ceil(log2(allocationSize));

	for(int i = index; i < MEM_MAX_SEG; i++)
	{
		if(mem[i] > 0)
		{
			memIndex = i;
			mem[i]--;

			freeSpace = pow(2.0, static_cast<double>(i)) - allocationSize;

			if(freeSpace)
				numFragments++;
	
			freeMem -= allocationSize;
			return true;
		}
	}
	
	return false;
}

bool Segregated::deallocate()
{
	mem[memIndex]++;

	if(freeSpace)
		numFragments--;

	freeMem += allocationSize;

	return true;
}

int Segregated::getFragments()
{
	return numFragments;
}

int Segregated::getFreeMem()
{
	return freeMem;	
}
