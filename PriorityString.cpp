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

ostream& operator<< (ostream& stream, PriorityString& ps)
{
	return stream << setw(5) << ps.getPriority() << " : " << ps.getData() << endl ;
}