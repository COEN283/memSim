/****************************************************************************************

	Class Name:		
		

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef BESTFIT_H
#define BESTFIT_H

#include <iostream>
#include "allocation.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class BestFit : public Allocation
{
	private:
		// Memory Array		
		static bool memory[MEM_SIZE];
		int memPos;

	public:

		BestFit(unsigned int start, unsigned int size, unsigned int finish);
		~BestFit();
		bool allocate();
        bool deallocate();
		int getFragments();
};

bool BestFit::memory[MEM_SIZE] = {false};

#endif
