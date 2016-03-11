/****************************************************************************************
	Description:	
					
	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.4 

****************************************************************************************/

#include <iostream>

using namespace std;

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

//***************************************************************************************
// Classes
//***************************************************************************************
#include <string>

#include "allocation.h"
#include "calculon.h"

#include "firstFit.h"
#include "nextFit.h"
#include "bestFit.h"
#include "worstFit.h"
#include "binaryBuddy.h"
#include "doubleBuddy.h"
#include "segregated.h"
#include "simpleSegregated.h"

using namespace std;

//***************************************************************************************
// Prototypes
//***************************************************************************************

//***************************************************************************************
// Main Function
//***************************************************************************************

int main()
{
	string testfile = "testfile.csv";
	string random = "random.csv";

	Calculon<FirstFit> firstFit(testfile, random, "first_fit_stats.csv");
	firstFit.runSimulation();
  
	Calculon<NextFit> nextFit(testfile, random, "next_fit_stats.csv");
	nextFit.runSimulation();
  
	Calculon<BestFit> bestFit(testfile, random, "best_fit_stats.csv");
	bestFit.runSimulation();
  
	Calculon<WorstFit> worstFit(testfile, random, "worst_fit_stats.csv");
	worstFit.runSimulation();
  
	Calculon<SimpleSegregated> simple(testfile, random, "simple_seg_stats.csv");
	simple.runSimulation();
  
	Calculon<Segregated> segregated(testfile, random, "segregated_stats.csv");
	segregated.runSimulation();
  
	Calculon<BinaryBuddy> binary(testfile, random, "binary_buddy_stats.csv");
	binary.runSimulation();
	
	Calculon<DoubleBuddy> doubleBuddy(testfile, random, "double_buddy_stats.csv");
	doubleBuddy.runSimulation();

	return 0;
}

//***************************************************************************************
// Function Definitions
//***************************************************************************************


