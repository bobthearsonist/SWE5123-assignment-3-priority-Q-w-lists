#include "PriorityString.h"
#include <iostream>
#include <iomanip>

using namespace std;

PriorityString::PriorityString()
{
	payload="";
	priority=0;
}

PriorityString::PriorityString( const string&s )
{
	payload=s;
	priority=0;
}

PriorityString::PriorityString( const string&s, unsigned n )
{
	payload=s;
	priority=n;
}

int PriorityString::getPriority() const
{
	return priority;
}

string PriorityString::getData() const
{
	return payload;
}

void PriorityString::setPriority( unsigned n)
{
	priority=n;
}

//This function only compares the priority so that it can be used by the
//list serach methods
bool PriorityString::operator==(PriorityString& comparand)
{
	return this->priority == comparand.priority;
}

ostream& operator<< (ostream& stream, PriorityString& ps)
{
	return stream << setw(5) << ps.getPriority() << " : " << ps.getData() << endl ;
}

