/****************************************************************************************

	Class Name:		
		

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef WORSTFIT_H
#define WORSTFIT_H

#include <iostream>
#include "allocation.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class WorstFit : public Allocation
{
	private:
		// Memory Array		
		static bool memory[MEM_SIZE];
        static int amountAllocated;
		int memPos;

	public:

		WorstFit(int start, int size, int finish);
		~WorstFit();
		bool allocate();
        bool deallocate();
		int getFragments();
        int getFreeMem();
};

#endif
