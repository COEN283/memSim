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

typedef priority_queue<Allocation*, vector<Allocation*> ,SortByAllocation> pqueue;

class Altron
{
	private:
		unsigned int time;
		ofstream outfile;
	
		pqueue allocationQueue; 
		
		// LL for elements
		// Queue for incoming elements		
	
	public:
	
		// Altron Constructor / Destructor
		Altron(string allocationFile, string randomAllocationFile);
		~Altron();
	
		// Read into Queue member function
		void populateQueue(string filename, pqueue& queue);
		// Increment time member function
		void incrementTime();
		// Count statistics
		void calculateStats();
};

#endif
