/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "allocation.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
Allocation::Allocation(int start, int size, int finish)
	:allocationTime(start), allocationSize(size), deallocationTime(finish)
{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
int Allocation::getStart()
{
	return allocationTime;
}

int Allocation::getSize()
{
	return allocationSize;
}

int Allocation::getFinish()
{
	return deallocationTime;
}


