/****************************************************************************************

	Class Name:		
		

	Purpose:		

	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef	ALLOCATION_H
#define ALLOCATION_H

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************
const unsigned int MEM_SIZE = 100; 

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Allocation
{
	protected:
		unsigned int allocationTime;
		unsigned int allocationSize;
		unsigned int deallocationTime;

	public:
		Allocation(unsigned int start, unsigned int size, unsigned int finish);
		virtual ~Allocation();

		unsigned int getStart();
		unsigned int getSize();
		void setFinish(int startTime);
		unsigned int getFinish();

		virtual bool allocate() const = 0;
		virtual bool deallocate() const = 0;
		virtual bool getFragments() const = 0;

		friend class SortByAllocation;
		friend class SortBySize;
		friend class SortByDeallocation;
};

class SortByAllocation
{
	public:
		bool operator()(const Allocation* lhs, const Allocation* rhs)
		{
			return lhs->allocationTime < rhs->allocationTime;
		} 
};

class SortBySize
{
	public:
		bool operator()(const Allocation* lhs, const Allocation* rhs)
		{
			return lhs->allocationSize < rhs->allocationSize;
		}
		
};

class SortByDeallocation
{
	public:
		bool operator()(const Allocation* lhs, const Allocation* rhs)
		{
			return lhs->deallocationTime < rhs->deallocationTime;
		}
};

#endif
