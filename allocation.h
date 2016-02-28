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
// Class Definition
//***************************************************************************************

class Allocation
{
	private:
		unsigned int allocationTime;
		unsigned int allocationSize;
		unsigned int deallocationTime;
		// Todo: Add way to make deallocation time = lifetime + allocation time

	public:
		Allocation(unsigned int start, unsigned int size, unsigned int finish);
		unsigned int getStart();
		unsigned int getSize();
		void setFinish(int startTime);
		unsigned int getFinish();

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
