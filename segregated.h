/****************************************************************************************

	Class Name:		
		

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef SEGREGATED_H
#define SEGREGATED_H

#include <iostream>
#include "allocation.h"

using namespace std;

const int MEM_MAX_SEG = 10;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Segregated : public Allocation 
{
	private:
		static int mem[MEM_MAX_SEG];
		static int numFragments;
		static int freeMem;

		int memIndex;
		int freeSpace;

	public:
		Segregated(int start, int size, int finish);
		~Segregated();
		bool allocate();
		bool deallocate();
		int getFragments();
		int getFreeMem();

};

#endif
