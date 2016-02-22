/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "allocation.h"
#include "altron.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************
const char DELIMITERS[] = " ,";
const string FILENAME = "stats.txt";
const int BUFFER_SIZE = 30;

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

Altron::Altron(string allocationFile, string randomAllocationFile)
{
	// Setup output writer for Stats
	outfile.open(FILENAME.c_str()); 
	
	// check for successful open
	if(!outfile)
	{
		cerr << "Error in opening output file: " << FILENAME << endl;
		exit(1);
	}
	
	// setup Allocation queue
	populateQueue(allocationFile, allocationQueue);
	populateQueue(randomAllocationFile, allocationQueue);

	// set time to 0
	time = 0;

	// setup memory array	
}

Altron::~Altron()
{
	// close outfile
	outfile.close();
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/* increment time
{
	// time++	

	// Read deallocation linked list
	// deallocate what isn't needed anymore
	
	// Read allocation queue
	// allocate what needs to be allocated
}
*/

// Parse file
void Altron::populateQueue(string filename, pqueue& queue)
{
	char buffer[BUFFER_SIZE];

	int allocationTime;
	int allocationSize;
	int deallocationTime;

	// Open file pointer
	ifstream infile(filename.c_str()); 
	
	// check for successful open
	if(!infile)
	{
		cerr << "Error in opening input file: " << FILENAME << endl;
		exit(1);
	}
	
	while( infile.getline(buffer,BUFFER_SIZE) )
	{
		allocationTime   = atoi(strtok(buffer, DELIMITERS));
		allocationSize   = atoi(strtok(NULL  , DELIMITERS));
		deallocationTime = atoi(strtok(NULL  , DELIMITERS));

		Allocation* tempAllocation = 
				new Allocation(allocationTime, allocationSize, deallocationTime);

		queue.push(tempAllocation);
	}

	// close infile
	infile.close();
}

