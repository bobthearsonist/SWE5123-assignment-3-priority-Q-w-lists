#ifndef PRIORITYSTRING_H
#define PRIORITYSTRING_H

#include <string>
#include <iostream>

using namespace std;

class PriorityString
{

	protected:
		string	payload;	// our data element to enqueue
		int	priority;	// our priority value
	
	public:
		PriorityString();
		PriorityString( const string& s);
		PriorityString( const string& s, unsigned n);

		// Postcondition: the integer returned is the priority of this element
		int getPriority() const;

		// Postcondition:  the string returned is the payload of this element
		string getData() const;

		// Postcondition: the priority of PriorityString is changed to n
		void setPriority( unsigned n);

	// Postcondition: The string value of PriorityString has been read in from stream.
	friend istream& operator>> (istream& stream, PriorityString& ps);

	// Postcondition: The string value of PriorityString has been output to stream.
	friend ostream& operator<< (ostream& stream, PriorityString& ps);


}; // PriorityString


#endif