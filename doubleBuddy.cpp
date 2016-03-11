/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <cmath>
#include "doubleBuddy.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************
//                                         0    1    2   3   4  5  6  7  8  9
int DoubleBuddy::memRight[MEM_MAX_DBL] = {265, 128, 64, 32, 16, 8, 4, 2, 1, 0};
//                                        0    1   2  3  4  5  6  7  8  9
int DoubleBuddy::memLeft[MEM_MAX_DBL] = {243, 81, 27, 9, 3, 1, 0, 0, 0, 0};
									//	{265, 85, 29, 9, 3, 1, 0, 0, 0, 0};
int DoubleBuddy::numFragments = 0;
int DoubleBuddy::freeMem = MEM_SIZE;
double DoubleBuddy::rightBase = 2.0;
double DoubleBuddy::leftBase = 3.0;

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

	for(; rightIndex < MEM_MAX_DBL; rightIndex++)
		if(memRight[rightIndex] > 0)
			break;

	for(; leftIndex < MEM_MAX_DBL; leftIndex++)
		if(memLeft[leftIndex] > 0)
			break;
	
	if(pow(rightBase, rightIndex) <= pow(leftBase, leftIndex))
		rightTree = true;
	else
		rightTree = false;

	if(rightTree && rightIndex >= MEM_MAX_DBL)
		return false;

	if(!rightTree && leftIndex >= MEM_MAX_DBL)
		return false;


	if(rightTree)
	{
        for(int j = rightIndex + 1; j < MEM_MAX_DBL; j++)
            memRight[j]--;

        for(int j = rightIndex; j > 0; j--)
            memRight[j] -= pow(rightBase, rightIndex - j);
	
		memIndex = rightIndex;
	
		freeSpace = pow(rightBase, static_cast<double>(rightIndex)) - allocationSize;
	}
	else
	{
		for(int j = leftIndex + 1; j < MEM_MAX_DBL; j++)
			memLeft[j]--;
		
		for(int j = leftIndex; j > 0; j--)
			memLeft[j] -= pow(leftBase, leftIndex - j);
		
		memIndex = leftIndex;
		
		freeSpace = pow(leftBase, static_cast<double>(leftIndex)) - allocationSize;
	}

	if(freeSpace)
		numFragments++;
	
	freeMem -= allocationSize;

	return true;
}

bool DoubleBuddy::deallocate()
{
	for(int j = memIndex + 1; j < MEM_MAX_DBL; j++)
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

	if(freeSpace)
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
