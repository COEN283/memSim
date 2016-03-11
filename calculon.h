/****************************************************************************************

	Class Name:		
	

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef CALCULON_H
#define CALCULON_H

//***************************************************************************************
// Includes
//***************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include <queue>
#include <list>
#include <vector>

#include "allocation.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

template <typename A>
class Calculon
{
	private:
		unsigned int time;
		ofstream outfile;

		// allocation and deallocation queues	
		priority_queue<A*, vector<A*>, SortByAllocation> allocationQueue; 
		priority_queue<A*, vector<A*>, SortByDeallocation> deallocationQueue;
	
	public:
	
		// Calculon Constructor / Destructor
		Calculon(string allocationFile, string randomAllocationFile, string output);
		~Calculon();
	
		// runSimulation
		void runSimulation();
		// Read into Queue member function
		void populateQueue(string filename, priority_queue<A*, vector<A*>, SortByAllocation>& queue);
		// Increment time member function
		void incrementTime();
		// Count statistics
		void calculateStats(int numFailedAllocations, int numFragments, int numAllocations, int numDeallocations, int freeMem, int time);
};

#include "calculon.cpp"

#endif
