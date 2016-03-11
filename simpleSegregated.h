/****************************************************************************************

	Class Name:		
		

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef SIMPLESEGREGATED_H
#define SIMPLESEGREGATED_H

#include <iostream>
#include "allocation.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

const int CLASS_SIZE = 2;
const int MEM_MAX_SIM = 10;

class SimpleSegregated : public Allocation 
{
	private:
		static int mem[MEM_MAX_SIM];
		static int numFragments;
		static int freeMem;

		int memIndex;
		int freeSpace;

	public:
		SimpleSegregated(int start, int size, int finish);
		~SimpleSegregated();
		bool allocate();
		bool deallocate();
		int getFragments();
		int getFreeMem();

};

#endif
