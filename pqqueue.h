#ifndef LIST_PRIORITY_QUEUE
#define LIST_PRIORITY_QUEUE

#include "list1.h"		// or any other LL implementation you desire
#include "d_except.h"

const int MAXPRIORITY = 10;

template <typename T>
class pqqueue
{
	public:
		pqqueue();			// default constructor
		~pqqueue();			// destructor
		pqqueue(const pqqueue& pq);	// copy constructor

		void push(const T& item);
			// insert item with priority p, derived from the item somehow.
			// 0 <= p <= MAXPRIORITY
			// Precondition: item has member method getPriority that return priority of the item as an int
			// Postcondition: the queue has one more element

		void push(const T& item, int p);
			// insert item with priority p
			// 0 <= p <= MAXPRIORITY
			// Postcondition: the queue has one more element

		void pop();
			// find the non-empty queue with largest index and remove
			// its front element
			// Precondition: the queue is not empty. the function
			// can throw the underflowError exception if the queue is empty
			// void pop() throw ( underflowError )

		T& top();
			// find the non-empty queue with largest index and return
			// its front element
			// Precondition: the queue is not empty. the function
			// can throw the underflowError exception if the queue is empty
			// T& top() throw ( underflowError )

		const T& top() const;
			// constant version of top()

		bool empty() const;
			// is the queue empty?
		int size() const;
			// return the number of elements in the queue

		pqqueue& operator=(const pqqueue& pq);
			// assignment operator
			// set ourselves equal to another queue


	// NONMEMBER FUNCTIONS FOR PQQUEUE
		//friend pqqueue& operator+(const pqqueue& pq1, const pqqueue& pq2);
		// put two queues together, keeping priority meaningful

		friend std::ostream& operator<<(std::ostream& out, const pqqueue& pq);
		// output the queue showing values and priority


	private:
		List<T> priority;
			// priority contains all elements managed by priority
			// in the their order of insertion
			// you may implement any Linked List you want; just do it correctly.

		int pqsize;
		// number of elements in the priority queue across all queues

	//PRIVATE helper functions
		//this function handles the sorted insert, thus keeping seperation of concerns
		//returns a pointer instead of a reference becaus ethats what node.insert needs
		//TODO implement a sorted_list class that inherits from list and overrides insert
		node<T>* push_search_helper(int priority);
		void check_underflow(void);
		T& top_helper(void);
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

//this function relys on a proper copy constructor definition for List
//the provided class will suffice with a default copy constructor becasue it
//will copy the head pointer by value
//both lists will pioint to the same items!
template <typename T>
pqqueue<T>::pqqueue(const pqqueue& target)
{
	this->pqsize = target.pqsize;
	this->priority = target.priority;
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

//this function assumes that T has a member priority. attempting to use this calss with objects lacking this member
//will result in a runtime error.
template <typename T>
void pqqueue<T>::push(const T& item)
{
	push(item, item.getPriority());
};

template <typename T>
void pqqueue<T>::push(const T& item, int p)
{
	//item cannot be null here because a reference must be bound during initialization. It can be invalid, but thats
	//your problem, not mine.

	//TODO push this into list.push() or a new sorted_list.push inheriting from list. then set get_head to private
	//we must test for an empty list here becasue the list_insert fucntion does not validate input arguments
	if (this->size() == 0)
	{
		node<T>* head = priority.get_head();
		list_head_insert(head,item);
	}
	else
	{
		list_insert(push_search_helper(p), item);
	}
	++this->pqsize;
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

template <typename T>
T& pqqueue<T>::top_helper(void)
{

	--pqsize;

	return priority.get_front();
}

template <typename T>
void pqqueue<T>::pop()
{
	int i = MAXPRIORITY;
	
};

template <typename T>
T& pqqueue<T>::top()
{
	int i = MAXPRIORITY;

	// ADD YOUR LOGIC HERE
	// same logic as pop, only return item
};

template <typename T>
const T& pqqueue<T>::top() const
{
	int i = MAXPRIORITY;

	// ADD YOUR LOGIC HERE
	// same logic as non const top
};

template <typename T>
bool pqqueue<T>::empty() const
{
	// ADD YOUR LOGIC HERE
	// determine if priority queue is empty
};

template <typename T>
int pqqueue<T>::size() const
{
	return pqsize;
}

template<typename T>
inline pqqueue<T> & pqqueue<T>::operator=(const pqqueue & pq)
{
	// TODO: insert return statement here
}
#endif	// LIST_PRIORITY_QUEUE
