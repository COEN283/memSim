/****************************************************************************************

	Class Name:		
	

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef ALTRON_H
#define ALTRON_H

//***************************************************************************************
// Includes
//***************************************************************************************

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include <queue>
#include <list>
#include <vector>

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************


typedef priority_queue<Allocation*, vector<Allocation*> ,SortByAllocation> allocQ;
typedef priority_queue<Allocation*, vector<Allocation*> ,SortByDeallocation> deallocQ;

template <typename A>
class Calculon
{
	private:
		unsigned int time;
		ofstream outfile;

		// allocation and deallocation queues	
		allocQ allocationQueue; 
		deallocQ deallocationQueue;
	
	public:
	
		// Calculon Constructor / Destructor
		Calculon(string allocationFile, string randomAllocationFile);
		~Calculon();
	
		// runSimulation
		void runSimulation();
		// Read into Queue member function
		void populateQueue(string filename, allocQ& queue);
		// Increment time member function
		void incrementTime();
		// Count statistics
		void calculateStats();
};

#endif
