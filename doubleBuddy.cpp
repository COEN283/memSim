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
const int MEM_MAX = 4;

#include "doubleBuddy.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
DoubleBuddy::DoubleBuddy(int start, int size, int finish):
Allocation(start, size, finish)
{}

DoubleBuddy::~DoubleBuddy()

{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
bool DoubleBuddy::allocate()
{
	int rightIndex = ceil(log2(allocationSize) / log2(rightBase));
	int leftIndex = ceil(log2(allocationSize) / log2(leftBase));

	for(; rightIndex < MEM_MAX; rightIndex++)
		if(memRight[rightIndex] > 0)
			break;

	for(; leftIndex < MEM_MAX; leftIndex++)
		if(memLeft[leftIndex] > 0)
			break;
	
	if(pow(rightBase, rightIndex) <= pow(leftBase, leftIndex))
		rightTree = true;
	else
		rightTree = false;

	if(rightTree && rightIndex == MEM_MAX)
		return false;

	if(!rightTree && leftIndex == MEM_MAX)
		return false;


	if(rightTree)
	{
        for(int j = rightIndex + 1; j < MEM_MAX; j++)
            memRight[j]--;

        for(int j = rightIndex; j > 0; j--)
            memRight[j] -= pow(rightBase, rightIndex - j);
	
		memIndex = rightIndex;
	
		freeSpace = pow(rightBase, static_cast<double>(rightIndex)) - allocationSize;
	}
	else
	{
		for(int j = leftIndex + 1; j < MEM_MAX; j++)
			memLeft[j]--;
		
		for(int j = leftIndex; j > 0; j--)
			memLeft[j] -= pow(leftBase, leftIndex - j);
		
		memIndex = leftIndex;
		
		freeSpace = pow(leftBase, static_cast<double>(leftIndex)) - allocationSize;
	}

	if(!freeSpace)
		numFragments++;
	
	freeMem -= allocationSize;

	return true;
}

bool DoubleBuddy::deallocate()
{
	for(int j = memIndex + 1; j < MEM_MAX; j++)
	{
		if(rightTree)
		{
			memRight[j]++;
		}
		else
		{
			memLeft[j]++;
		}
	}
	
	for(int j = memIndex; j > 0; j--)
	{
		if(rightTree)
		{
			memRight[j] += pow(rightBase, memIndex - j);
		}
		else
		{
			memLeft[j] += pow(leftBase, memIndex - j);
		}
	}

	if(!freeSpace)
		numFragments--;
	
	freeMem += allocationSize;

	return true;
}

int DoubleBuddy::getFragments()
{
	return numFragments;
}

int DoubleBuddy::getFreeMem()
{
	return freeMem;	
}
