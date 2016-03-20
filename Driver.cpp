// Example Driver File
// Author: David Stabler

#include "PriorityString.h"
#include <iostream>
#include <string>
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
	//they should appear in the list as 1,4,2,3
	PQ3.push(PriorityString("negative 1"), -3);
	PQ3.push(PriorityString("negative 2"), -5);
	PQ3.push(PriorityString("negative 3"), -5);
	PQ3.push(PriorityString("negative 4"), -4);
	cout << PQ3 << endl;


	//Iw as having troubles with the order and my suspicion was that it was on the insert of the underlying list
	//not my iterator/comparison for the priority
	pqqueue<PriorityString> PQ4;
	PQ4.push(PriorityString("1", 1));
	PQ4.push(PriorityString("2", 2));
	PQ4.push(PriorityString("3", 3));
	PQ4.push(PriorityString("4", 4));
	PQ4.push(PriorityString("5", 5));
	PQ4.push(PriorityString("6", 6));
	PQ4.push(PriorityString("7", 7));

	cout << PQ4 << endl;
	//see if it is at the first repeat priority
	PQ4.push(PriorityString("4 2", 4));
	
	cout << PQ4 << endl;
	//see if it is on the second repeated priority insert
	PQ4.push(PriorityString("6 2", 6));

	cout << PQ4 << endl;
	//see if its on repeats at the head
	PQ4.push(PriorityString("7 2", 7));
	
	cout << PQ4 << endl;

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