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

class Segregated : public Allocation 
{
	private:
		static int mem[MEM_MAX];
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

int Segregated::mem[MEM_MAX] = {8,4,2,1};
int Segregated::numFragments = 0;
int Segregated::freeMem = 0;

#endif
