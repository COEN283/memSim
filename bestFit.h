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

class bestFit : public Allocation
{
	private:
		// Memory Array		
		static bool memory[MEM_SIZE];
		int memPos;

	public:

		bestFit(unsigned int start, unsigned int size, unsigned int finish);
		~bestFit();
		bool allocate();
		bool deallocate();
};

bool bestFit::memory[MEM_SIZE] = {false};

#endif
