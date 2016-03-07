/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <cmath>

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

const int CLASS_SIZE = 2;
const int MEM_MAX = 4;

#include "simpleSegregated.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
SimpleSegregated::SimpleSegregated(int start, int size, int finish):
Allocation(start, size, finish)
{}

SimpleSegregated::~SimpleSegregated()

{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool SimpleSegregated::allocate()
{
	int index = ceil(log2(allocationSize));

	if(!(index % CLASS_SIZE))
		index += (CLASS_SIZE - (index % CLASS_SIZE));

	for(int i = index; i < MEM_MAX; i += CLASS_SIZE)
	{
		if(mem[i] > 0)
		{
			memIndex = i;
			mem[i]--;
			freeSpace = pow(2.0, static_cast<double>(i)) - allocationSize;
			if(!freeSpace)
				numFragments++;
	
			freeMem -= allocationSize;
			return true;
		}
	}

	return false;
}

bool SimpleSegregated::deallocate()
{
	mem[memIndex]++;

	if(!freeSpace)
		numFragments--;

	freeMem += allocationSize;

	return true;
}

int SimpleSegregated::getFragments()
{
	return numFragments;
}

int SimpleSegregated::getFreeMem()
{
	return freeMem;	
}
