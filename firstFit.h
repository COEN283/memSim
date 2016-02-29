/*
 * FirstFit.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Sisi Yang
 *    IDE Used: Eclipse Luna 4.4.0 for C++ (Mac OSX El Capitan version 10.11.2)
 *    
 */
//This program is created for COEN283 project.

#include <allocation.h>
#include <allocation.cpp>

#ifndef FIRSTFIT_H_
#define FIRSTFIT_H_

class FirstFit: public Allocation
{
private:
	//MEM_SIZE is 100, unsigned int
	static unsigned int memArr[MEM_SIZE] = {0};

	//keeps track of allocated location in memory
	unsigned int memLoc = 0;

public:
	//constructor
	FirstFit(unsigned int start, unsigned int size, unsigned int finish);

	//destructor
	~FirstFit();

	//allocation
	bool allocate();

	//deallocation
	bool deallocate();

	//collected fragmentation stats
	int getFragments();

};

#endif /* FIRSTFIT_H_ */
