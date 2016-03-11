/****************************************************************************************

	Purpose:		Source file for 

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************
const char DELIMITERS[] = " ,";
const int BUFFER_SIZE = 30;

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

template <typename A>
Calculon<A>::Calculon(string allocationFile, string randomAllocationFile, string output)
{
	// Setup output writer for Stats
	outfile.open(output.c_str()); 

	// Print out header
	outfile << "time" << ", " << "numFragments" << ", " << "numFailedAllocations" 
			<< ", " << "numAllocations" << ", " << "numDeallocations" << ", " 
			<< "freeMem" << endl;

	
	// check for successful open
	if(!outfile)
	{
		cerr << "Error in opening output file: " << output << endl;
		exit(1);
	}
	
	// setup Allocation queue
	populateQueue(allocationFile, allocationQueue);
	populateQueue(randomAllocationFile, allocationQueue);

	// set time to 0
	time = 0;

	// setup memory array	
}

template <typename A>
Calculon<A>::~Calculon()
{
	// close outfile
	outfile.close();
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

// increment time
template <typename A>
void Calculon<A>::incrementTime()
{
	time++;	

	int numFailedAllocations = 0;
	int numFragments = 0;
	int numAllocations = 0;
	int numDeallocations = 0;
	int freeMem = 0;

	vector <A*> allocationHold;

	// Read deallocation Queue
	// deallocate what isn't needed anymore
	while( !deallocationQueue.empty() && 
				deallocationQueue.top()->getFinish() <= time )
	{
		// deallocate the object
		deallocationQueue.top()->deallocate();
		
		delete(deallocationQueue.top());

		deallocationQueue.pop();

		numDeallocations++;
	}
	
	// Read allocation queue
	// allocate what needs to be allocated
	while( !allocationQueue.empty() &&
			 allocationQueue.top()->getStart() <= time )
	{
		// if successfully allocated
		if( allocationQueue.top()->allocate() )
		{
			allocationQueue.top()->setFinish(time);			
            
			deallocationQueue.push(allocationQueue.top());

			allocationQueue.pop();

			numAllocations++;
		}
		else
		{
			if(allocationQueue.top()->getFreeMem() > 
					allocationQueue.top()->getSize())
			{
				numFailedAllocations++;
			}

            allocationHold.push_back(allocationQueue.top());

            allocationQueue.pop();
		}
	}

    while(!allocationHold.empty())
    {
        allocationQueue.push(allocationHold.back());
        allocationHold.pop_back();
    }

	if(!allocationQueue.empty())
	{
		numFragments = allocationQueue.top()->getFragments();			
		freeMem = allocationQueue.top()->getFreeMem();			
	}

	this->calculateStats(numFailedAllocations, numFragments,
			numAllocations, numDeallocations, freeMem, time);
}


// Parse file
template <typename A>
void Calculon<A>::populateQueue(string filename, priority_queue<A*, vector<A*>, SortByAllocation>& queue)
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
		cerr << "Error in opening input file: " << filename << endl;
		exit(1);
	}
	
	while( infile.getline(buffer,BUFFER_SIZE) )
	{
		allocationTime   = atoi(strtok(buffer, DELIMITERS));
		allocationSize   = atoi(strtok(NULL  , DELIMITERS));
		deallocationTime = atoi(strtok(NULL  , DELIMITERS));

		A* tempAllocation = 
				new A(allocationTime, allocationSize, deallocationTime);

		queue.push(tempAllocation);
	}

	// close infile
	infile.close();
}

template <typename A>
void Calculon<A>::calculateStats(int numFailedAllocations, int numFragments, int numAllocations, int numDeallocations, int freeMem, int time)
{
	outfile << time << ", " << numFragments << ", " << numFailedAllocations 
		<< ", " << numAllocations << ", " << numDeallocations << ", " << freeMem << endl;
}

template <typename A>
void Calculon<A>::runSimulation()
{
	while(!allocationQueue.empty() || !deallocationQueue.empty())
	{
		incrementTime();
	}
}
