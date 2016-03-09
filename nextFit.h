/*
 * NextFit.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Sisi Yang
 *    IDE Used: Eclipse Luna 4.4.0 for C++ (Mac OSX El Capitan version 10.11.2)
 *    
 */
//This program is created for COEN283 project.

#ifndef NEXTFIT_H_
#define NEXTFIT_H_

#include "allocation.h"

class NextFit: public Allocation
{
private:
	//MEM_SIZE is 100, int
	static int memArr[MEM_SIZE];

	//keeps track of allocated location in memory
	int memLoc = 0;

	//keeps track of amount of allocated memory
    static int allocatedMem;
    static int currIndex;

public:
	//constructor
	NextFit(int start, int size, int finish);

	//destructor
	~NextFit();

	//allocation
	bool allocate();

	//deallocation
	bool deallocate();

	//get number of fragments
	int getFragments();

	//get amount of free memory
	int getFreeMem();

};


#endif /* NEXTFIT_H_ */
