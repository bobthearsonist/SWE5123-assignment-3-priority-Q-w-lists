// Example Driver File
// Author: David Stabler

// #include "pqqueue.h"
#include "PriorityString.h"
#include <iostream>
#include <string>
#include "Node1.h"

using namespace std;	// required for string

void main()
{

	string i="hi there";
 	PriorityString ps("String with Priority 5", 5);

    node<PriorityString>* headptr;

	headptr=new node<PriorityString>(ps);

 	PriorityString ps2("String with Priority 4", 4);

	list_insert(headptr, ps2);

	list_head_insert(headptr, PriorityString("String with Priority 3", 3) );

	cout << list_length( headptr ) << endl ;

	node<PriorityString>* cursor = headptr;
	while ( cursor != NULL )
	{
		cout <<  cursor->data() << endl;
		cursor = cursor->link();
	}

	/*
	pqqueue<PriorityString> PQ;

	PQ.push( PriorityString("Test String 1", 1) );
	PQ.push( ps );
	PQ.push( PriorityString("Test String 2", 2), 2);

	pqqueue<PriorityString> PQ2;

	PQ2.push( PriorityString("Quick", 7);
	PQ2.push( PriorityString("Fox", 6);
	PQ2.push( PriorityString("The", 2);
	PQ2.push( PriorityString("Lazy", 1);
	PQ2.push( PriorityString("Jumps", 4);
	PQ2.push( PriorityString("Dog");
	PQ2.push( PriorityString("Brown", 7);
	PQ2.push( PriorityString("Over", 4);
	PQ2.push( PriorityString("The", 9);
	PQ2.push( PriorityString(".");

	cout << i << endl;
	cout << ps << endl;
	cout << PQ << endl;
	cout << PQ2 << endl;

	pqqueue<PriorityString> PQ3 = PQ + PQ2;
	cout << PQ3 << endl;
*/	
}