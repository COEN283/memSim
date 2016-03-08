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

//***************************************************************************************
// Class Definition
//***************************************************************************************

const int MEM_MAX = 4;

class DoubleBuddy : public Allocation 
{
	private:
		static int memRight[MEM_MAX];
		static int memLeft[MEM_MAX];
		static int numFragments;
		static int freeMem;
		static double rightBase;
		static double leftBase;

		int memIndex;
		int freeSpace;
		bool rightTree;

	public:
		DoubleBuddy(int start, int size, int finish);
		~DoubleBuddy();
		bool allocate();
		bool deallocate();
		int getFragments();
		int getFreeMem();

};

#endif
