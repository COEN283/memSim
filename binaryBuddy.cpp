/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <cmath>
#include "binaryBuddy.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

int BinaryBuddy::mem[MEM_MAX] = {8,4,2,1};
int BinaryBuddy::numFragments = 0;
int BinaryBuddy::freeMem = 0;

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

	for(int i = index; i < MEM_MAX; i++)
	{
		if(mem[i] > 0)
		{
			memIndex = i;
            
            for(int j = i + 1; j < MEM_MAX; j++)
                mem[j]--;

            for(int j = i; j > 0; j--)
                mem[j] -= pow(2.0, i - j);

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
    for(int j = memIndex + 1; j < MEM_MAX; j++)
        mem[j]++;

    for(int j = memIndex; j > 0; j--)
        mem[j] += pow(2.0, memIndex - j);

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
