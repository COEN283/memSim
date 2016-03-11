/****************************************************************************************

	Class Name:		
		

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef BINARYBUDDY_H
#define BINARYBUDDY_H

#include <iostream>
#include "allocation.h"

using namespace std;

const int MEM_MAX = 10;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class BinaryBuddy : public Allocation 
{
	private:
		static int mem[MEM_MAX];
		static int numFragments;
		static int freeMem;

		int memIndex;
		int freeSpace;

	public:
		BinaryBuddy(int start, int size, int finish);
		~BinaryBuddy();
		bool allocate();
		bool deallocate();
		int getFragments();
		int getFreeMem();

};

#endif
