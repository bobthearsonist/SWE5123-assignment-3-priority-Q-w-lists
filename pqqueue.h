#ifndef LIST_PRIORITY_QUEUE
#define LIST_PRIORITY_QUEUE

#include "list1.h"		// or any other LL implementation you desire
#include "d_except.h"

//max priority is now irrelevant and is only limited by the size of an integer.
//const int MAXPRIORITY = 10;

template <typename T>
class pqqueue
{
	public:
		pqqueue();			// default constructor
		~pqqueue();			// destructor
		pqqueue(const pqqueue& pq);	// copy constructor

		void push(const T& item);
			// insert item with priority p, derived from the item somehow.
			// priority is limited only by the size of int for the machine
			// Precondition: item has member method getPriority that returns priority of the item as an int
			// Postcondition: the queue has one more element

		//this push declaration modified to not take a const this in order to set the priority of item to p before the push
		//this accomodates my understanding of the "push with priority p" requirement of the original description. Since the list
		//does not understand anything but the priority of the item, the item must be set with priority p.
		void push(T& item, int p);
			// insert item with priority p
			// priority is limited only by the size of int for the machine
			// Postcondition: the queue has one more element

		void pop();
			// item with the largest priority is removed
			// Precondition: the queue is not empty. the function
			// can throw the underflowError exception if the queue is empty
			// void pop() throw ( underflowError )
		
		// my accesors here were changed to return copies. The underlying node class has absolute data encapsulation, meaning that the class
		// manages memory internally, and I cant get it. This strategy makes sens, we dont want to rely on the user to manage the memory, and
		// we cant trust them to not delete it either, so it copies on on the push and returns a copy on the pop.
		// (note we could have changed the underlying class to use refrences, or worse declared heap space, but I think this was the "best" way)
		T top();
			// item with the largest priority is returned
			// Precondition: the queue is not empty. the function
			// can throw the underflowError exception if the queue is empty
			// T& top() throw ( underflowError )

		const T top() const;
			// constant version of top()

		bool empty() const;
			// is the queue empty?
		int size() const;
			// return the number of elements in the queue

		pqqueue& operator=(const pqqueue& pq);
			// assignment operator
			// set ourselves equal to another queue


	// NONMEMBER FUNCTIONS FOR PQQUEUE
		//this function cannot reteurn a reference and take in two consts. it must either modify one of the input arguments, or
		//return by value a List created within the function. I chose the latter.
		friend pqqueue<T> operator+ <T>(const pqqueue<T>& pq1, const pqqueue<T>& pq2);
		// put two queues together, keeping priority meaningful
		// post-condition: The items of B are added to the queue of A. A is "first in line" as a result A+B!=B+A.
		template <typename T>
		friend ostream& operator<< <T>(ostream& out, const pqqueue<T>& pq);
		// output the queue showing values and priority


	private:
		List<T> priority;
			// priority contains all elements managed by priority
			// in the their order of insertion
			// you may implement any Linked List you want; just do it correctly.

		int pqsize;
		// number of elements in the priority queue across all queues

	//PRIVATE helper functions
		
		//handles the sorted insert, thus keeping seperation of concerns
		//returns a pointer instead of a reference becaus ethats what node.insert needs
		//TODO implement a sorted_list class that inherits from list and overrides insert
		node<T>* push_search_helper(int priority);
		//prevents duplicate code when dealing with checking for undeflows
		void check_underflow(void);
		//prevents duplicate conde when dealing with top
		T top_helper(void);
};


// TEMPLATES AND IMPLEMENTATION

// create an empty priority queue
template <typename T>
pqqueue<T>::pqqueue()
{
	pqsize = 0;
};

template <typename T>
pqqueue<T>::~pqqueue()
{
	//the list will be deleted in the destructor
	//delete priority;
	pqsize = 0;
};

template <typename T>
pqqueue<T>::pqqueue(const pqqueue<T>& target)
{
	//copy into new list
	NodeIterator<T> cursor(const_cast<pqqueue<T>&>(target).priority.get_head());
	while (cursor != NULL)
	{
		this->push((*cursor)->data());	//copy the values
		cursor++;						//move to next input
}
}

//this fuction retruns a pointer to the node of insertion for a given item
template <typename T>
node<T>* pqqueue<T>::push_search_helper(int target_priority)
{
	NodeIterator<T> cursor(priority.get_head());
	node<T>* prev = *cursor;
	//NULL test will let this work with empty list too! and protects second test from NULL dereference
	//>= means we will insert AFTER all current items of the same priority
	while (cursor != NULL && (*cursor)->data().getPriority() >= target_priority)//TODO implement with iterator and comparator
	{
		prev = *(cursor++);
	}
	return prev;
}

//this function assumes that T has a member function getPriority(). attempting to use this class with objects lacking this member
//will result in error.
template <typename T>
void pqqueue<T>::push(const T& item)
{
	//item cannot be null here because a reference must be bound during initialization. It can be invalid, but thats
	//your problem, not mine.

	//negative values are not rejected here as they can be sorted and therfore are valid priorities.

	//TODO push this into list.push() or a new sorted_list.push inheriting from list. then set get_head to private
	//we must test for an empty list here becasue the list_insert fucntion does not validate input arguments
	if (priority.get_head() == NULL || (priority.get_head())->data().getPriority() < item.getPriority())
	{
		list_head_insert(this->priority.get_head(), item);
	}
	else
	{
		list_insert(push_search_helper(item.getPriority()), item);
	}
	++this->pqsize;
};

//this operation is O(1) until the head is of larger priority than the inserted node, then it is O(n)
template <typename T>
void pqqueue<T>::push(T& item, int p)
{
	//item cannot be null here because a reference must be bound during initialization. It can be invalid, but thats
	//your problem, not mine.

	//negative values are not rejected here as they can be sorted and therfore are valid priorities.

	//override the item priority with the priority given if they are not equal
	if (item.getPriority() != p)
	{
		item.setPriority(p);
	}

	push(item);
};

template <typename T>
void pqqueue<T>::check_underflow(void)
{
	//I throw an error for the caller to deal with
	//Note that I do not test the underlying queue size here since we keep count in the pqqueue
	if (pqsize <= 0)
	{
		throw new underflowError();
	}
}

//check for underflow and then return a copy of the top item
template <typename T>
T pqqueue<T>::top_helper(void)
{
	check_underflow();
	return priority.get_front();
}

template <typename T>
void pqqueue<T>::pop()
{
	check_underflow();
	priority.delete_front();
	--pqsize;
};

template <typename T>
T pqqueue<T>::top()
{
	return top_helper();
};

template <typename T>
const T pqqueue<T>::top() const
{
	return top_helper();
};

template <typename T>
bool pqqueue<T>::empty() const
{
	return priority.size() > 0;
};

template <typename T>
int pqqueue<T>::size() const
{
	return pqsize;
}

//I chose to delete here, primarily becasue I was unsure of how this would work with the string data within Priority String. IT seems 
//like you could get away with reusing the node allcoations and doing a copy into the node
template<typename T>
inline pqqueue<T>& pqqueue<T>::operator=(const pqqueue & pq)
{
	//If we are ourselves, dont do anything!
	if (this == &pq)
	{
		return *this;
	}

	node<T>* hold_for_delete = this->priority.get_head();	//keep track to not cause a leak
	this->priority.get_head() = NULL;	//chop off the list
	
	//copy into new list
	NodeIterator<T> cursor(const_cast<pqqueue<T>&>(pq).priority.get_head());
	while (cursor != NULL)
{
		this->push((*cursor)->data());	//copy the values
		cursor++;						//move to next input
	}

	//delete old list
	delete hold_for_delete;

	return *this;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const pqqueue<T>& pq)
{
	// output the queue showing values and priority
	NodeIterator<T> cursor(const_cast<pqqueue<T>&>(pq).priority.get_head());
	while (cursor != NULL)
	{
		out << (*cursor)->data() << endl;
		cursor++;
	}
	return out;
}

//this simply reduces duplicate code form the operator=, operator+, and copy constructor
template<typename T>
void copy_helper(const pqqueue<T>& source, pqqueue<T> dest)
{
	NodeIterator<T> cursor(const_cast<pqqueue<T>&>(source).priority.get_head());//TODO fix const cast
	while (cursor != NULL)
	{
		pq.push((*cursor)->data());
		cursor++;
	}
}

//note that becasue we have chosen to keep the list sorted on the insert this operation is expensive because we must
//merge them. I do a very lazy merge. using two iterators to go through each list and insert would be much more efficient
//O(n). Here I have O(n^2) worst case.
template <typename T>
pqqueue<T> operator+(const pqqueue<T>& pq1, const pqqueue<T>& pq2)
{
	pqqueue<T> pq;

	//we want to copy the smaller pq into the larger one to reduce the number of inserts
	const pqqueue<T>* smaller;
	if (pq1.size() > pq2.size())
	{
		smaller = &pq2;
		pq = pq1;
	}
	else
	{
		smaller = &pq1;
		pq = pq2;
	}

	NodeIterator<T> cursor(const_cast<pqqueue<T>&>(*smaller).priority.get_head());//TODO fix const cast
	while (cursor != NULL)
	{
		pq.push((*cursor)->data());
		cursor++;
	}

	return pq;
}
#endif	// LIST_PRIORITY_QUEUE
