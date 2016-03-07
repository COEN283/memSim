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

#include "binaryBuddy.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
BinaryBuddy::BinaryBuddy(int start, int size, int finish):
Allocation(start, size, finish)
{}

BinaryBuddy::~BinaryBuddy()

{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool BinaryBuddy::allocate()
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

bool BinaryBuddy::deallocate()
{
	mem[memIndex]++;

	if(!freeSpace)
		numFragments--;

	freeMem += allocationSize;

	return true;
}

int BinaryBuddy::getFragments()
{
	return numFragments;
}

int BinaryBuddy::getFreeMem()
{
	return freeMem;	
}
