// FILE: node1.h
// PROVIDES: A class for a node in a linked list, and list manipulation
// functions, all within the namespace main_savitch_5
// Modified to be Templated by David Stabler
//
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is defined in the templated call and
//     is called T. The value type of T may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the node class:
//   node(
//     const T& init_data = T(),
//     node* init_link = NULL
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the T. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*).
// EXAMPLES:
//    const node *c;
//    c->link( ) activates the const version of link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->link( ) activates the non-const version of link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const T& new_data)
//     Postcondition: The node now contains the specified new data.
//
//   void set_link(node* new_link)
//     Postcondition: The node now contains the specified new link.
//
//   T data( ) const
//     Postcondition: The return value is the data from this node.
//
//   const node* link( ) const <----- const version
//   node* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node.
//
// FUNCTIONS in the linked list toolkit:
//   size_t list_length(const node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list.
//
//   void list_head_insert(node*& head_ptr, const node::T& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   void list_insert(node* previous_ptr, const node::T& entry)
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//
//   const node* list_search(const node* head_ptr, const node::T& target)
//   node* list_search(node* head_ptr, const node::T& target)
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned.
//
//   const node* list_locate(const node* head_ptr, size_t position)
//   node* list_locate(node* head_ptr, size_t position)
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned.
//
//   void list_head_remove(node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   void list_remove(node* previous_ptr)
//     Precondition: previous_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   void list_clear(node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//  void list_piece(
//    const node* start_ptr, const node* end_ptr,
//    node*& head_ptr, node*& tail_ptr
//  )
//    Precondition: start_ptr and end_ptr are pointers to nodes on the same
//    linked list, with the start_ptr node at or before the end_ptr node
//    Postcondition: head_ptr and tail_ptr are the head and tail pointers for a
//    new list that contains the items from start_ptr up to but not including
//    end_ptr.  The end_ptr may also be NULL, in which case the new list
//    contains elements from start_ptr to the end of the list.
//
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#ifndef MAIN_SAVITCH_NODE1_H
#define MAIN_SAVITCH_NODE1_H
#include <cstdlib> // Provides size_t and NULL

template< typename T>
    class node
    {
    public:

	// CONSTRUCTOR
	node<T>(
	    const T& init_data = T( ),
	    node* init_link = NULL
	)
	{ data_field = init_data; link_field = init_link; }

	// Member functions to set the data and link fields:
    	void set_data(const T& new_data) { data_field = new_data; }
    	void set_link(node<T>* new_link) { link_field = new_link; }

	// Constant member function to retrieve the current data:
	T data( ) const { return data_field; }

	// Two slightly different member functions to retreive
	// the current link:
	const node<T>* link( ) const { return link_field; }
    	  node<T>* link( )       { return link_field; }

	private:
	T          data_field;
	node<T>*   link_field;
    };

    // FUNCTIONS for the linked list toolkit
	template< typename T>
    size_t list_length(const node<T>* head_ptr);
	template< typename T>
    void list_head_insert(node<T>*& head_ptr, const T& entry);
	template< typename T>
    void list_insert(node<T>* previous_ptr, const T& entry);
	template< typename T>
	node<T>* list_search(node<T>* head_ptr, const T& target);
	template< typename T>
    const node<T>* list_search
	(const node<T>* head_ptr, const T& target);
	template< typename T>
    node<T>* list_locate(node<T>* head_ptr, size_t position);
	template< typename T>
    const node<T>* list_locate(const node<T>* head_ptr, size_t position);
	template< typename T>
    void list_head_remove(node<T>*& head_ptr);
	template< typename T>
    void list_remove(node<T>* previous_ptr);
	template< typename T>
    void list_clear(node<T>*& head_ptr);
	template< typename T>
    void list_copy(const node<T>* source_ptr, node<T>*& head_ptr, node<T>*& tail_ptr);

#include "Node1.tem"
template <typename T>
class NodeIterator
{
	/*
	This class implements an iterator for the provided node class
	Sources for i's implemntation were "inspired" by the text and
	the STL. All source was authored.
	*/
public:
	NodeIterator(node<T>* current = NULL)
	{
		this->current = current;
	}

	//postfix ++ operator
	//increments current to the next item and returns currents prev.
	//state
	NodeIterator operator++(int)
	{
		NodeIterator old(current);
		current = current->link();
		return old;
	}
	//TODO fix this operator and test it
	//prefix iterator
	//increments current to the next item and returns current
	NodeIterator& operator++(void)
	{
		current = current->link();
		return current;
	}

	bool operator!=(const NodeIterator& comparand) const
	{
		return this->current != comparand.current;
	}

	bool operator==(const NodeIterator& comparand) const
	{
		return this->current == comparand.current;
	}
	
	node<T>* operator*(void) const
	{
		return current;
	}

	//TODO add begin()
	//TODO add end()
private:
	node<T>* current;
};
#endif
