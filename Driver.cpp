// Example Driver File
// Author: David Stabler

#include "PriorityString.h"
#include <iostream>
#include <string>
#include "Node.h"
#include "pqqueue.h"

using namespace std;	// required for string

void main()
{


	string i="hi there";
 	PriorityString ps("String with Priority 5", 5);

	pqqueue<PriorityString> PQ;

	PQ.push( PriorityString("Test String 1", 1) );
	PQ.push( ps );
	PQ.push( PriorityString("Test String 2", 2), 2);

	pqqueue<PriorityString> PQ2;

	PQ2.push( PriorityString("Quick", 7));
	PQ2.push( PriorityString("Fox", 6));
	PQ2.push( PriorityString("The", 2));
	PQ2.push( PriorityString("Lazy", 1));
	PQ2.push( PriorityString("Jumps", 4));
	PQ2.push( PriorityString("Dog"));
	PQ2.push( PriorityString("Brown", 7));
	PQ2.push( PriorityString("Over", 4));
	PQ2.push( PriorityString("The", 9));
	PQ2.push( PriorityString("."));

	cout << i << endl;
	cout << ps << endl;
	cout << PQ << endl;
	cout << PQ2 << endl;

	pqqueue<PriorityString> PQ3 = PQ + PQ2;
	cout << PQ3 << endl;

	//test self assignment
	PQ3 = PQ3;
	cout << PQ3 << endl;

	//try some negative priorities and make sure they are sorted accordingly
	//they should appeasr in the list as 1,4,2,3
	PQ3.push(PriorityString("negative 1"), -3);
	PQ3.push(PriorityString("negative 2"), -5);
	PQ3.push(PriorityString("negative 3"), -5);
	PQ3.push(PriorityString("negative 4"), -4);
	cout << PQ3 << endl;
	//try our underflow exception
	try
	{
		while (1)
		{
			cout << PQ3.top();
			PQ3.pop();
		}
	}
	catch(exception e)
	{
		cout << e.what()<< endl;
	}
}