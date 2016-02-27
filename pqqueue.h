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
		friend pqqueue& operator+(const pqqueue& pq1, const pqqueue& pq2);
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
};


// TEMPLATES AND IMPLEMENTATION

// create an empty priority queue
template <typename T>
pqqueue<T>::pqqueue()
{
	// ADD YOUR LOGIC HERE
	// you need to allocate space for the List
	// and initialize any values you will use
};

template <typename T>
pqqueue<T>::~pqqueue()
{
	// ADD YOUR LOGIC HERE
	// you may need to deal with the dynamic nature of this
	// queue here
};

template <typename T>
void pqqueue<T>::push(const T& item)
{
	// ADD YOUR LOGIC HERE
	// push item into List where priority is derived somehow
	// or defaulted and increment priority queue size
};


template <typename T>
void pqqueue<T>::push(const T& item, int p)
{
	// ADD YOUR LOGIC HERE
	// push item into pq using priority p and increment priority queue size
};

template <typename T>
void pqqueue<T>::pop()
{
	int i = MAXPRIORITY;

	// ADD YOUR LOGIC HERE
	// if the priority queue is not empty
	// find a valid value in the list
	// remove, and decrement priority queue size
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

// NONMEMBER FUNCTION IMPLEMENTATIONS

template <typename T>
pqqueue<T>::pqqueue& operator+(const pqqueue<T>::pqqueue& pq1, const pqqueue<T>::pqqueue& pq2)
	// put two queues together, keeping priority meaningful

std::ostream& operator<<(std::ostream& out, const pqqueue& pq);
	// output the queue showing values and priority

#endif	// LIST_PRIORITY_QUEUE
