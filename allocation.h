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
		int allocationTime;
		int allocationSize;
		int deallocationTime;

	public:
		Allocation(int start, int size, int finish);
		int getStart();
		int getSize();
		int getFinish();

		friend class SortByAllocation;
		friend class SortBySize;
		friend class SortByDeallocation;
};

class SortByAllocation
{
	public:
		bool operator()(const Allocation& lhs, const Allocation& rhs)
		{
			return lhs.allocationTime < rhs.allocationTime;
		} 
};

class SortBySize
{
	public:
		bool operator()(const Allocation& lhs, const Allocation& rhs)
		{
			return lhs.allocationSize < rhs.allocationSize;
		}
		
};

class SortByDeallocation
{
	public:
		bool operator()(const Allocation& lhs, const Allocation& rhs)
		{
			return lhs.deallocationTime < rhs.deallocationTime;
		}
};

#endif
