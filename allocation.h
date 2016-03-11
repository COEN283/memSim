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
const int MEM_SIZE = 512; 

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Allocation
{
	protected:
		int allocationTime;
		int allocationSize;
		int deallocationTime;

	public:
		Allocation(int start, int size, int finish);
		virtual ~Allocation();

		int getStart();
		int getSize();
		void setFinish(int startTime);
		int getFinish();

		virtual bool allocate() = 0;
		virtual bool deallocate() = 0;
		virtual int getFragments() = 0;
		virtual int getFreeMem() = 0;

		friend class SortByAllocation;
		friend class SortBySize;
		friend class SortByDeallocation;
};

class SortByAllocation
{
	public:
		bool operator()(const Allocation* lhs, const Allocation* rhs)
		{
			return lhs->allocationTime > rhs->allocationTime;
		} 
};

class SortBySize
{
	public:
		bool operator()(const Allocation* lhs, const Allocation* rhs)
		{
			return lhs->allocationSize > rhs->allocationSize;
		}
		
};

class SortByDeallocation
{
	public:
		bool operator()(const Allocation* lhs, const Allocation* rhs)
		{
			return lhs->deallocationTime > rhs->deallocationTime;
		}
};

#endif
