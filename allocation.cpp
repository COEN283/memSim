/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "allocation.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************
Allocation::Allocation(unsigned int start, unsigned int size, unsigned int finish)
	:allocationTime(start), allocationSize(size), deallocationTime(finish)
{}

Allocation::~Allocation()
{}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************
unsigned int Allocation::getStart()
{
	return allocationTime;
}

unsigned int Allocation::getSize()
{
	return allocationSize;
}

void  Allocation::setFinish(int startTime)
{
	deallocationTime += startTime;
}

unsigned int Allocation::getFinish()
{
	return deallocationTime;
}


