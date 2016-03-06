//FILE: Link1.h
// [ some guidance gained from: http://www.daniweb.com/code/snippet216960.html ]
//
//TEMPLATE CLASS PROVIDED: List<Item> (a linked list of Items)
//   The template parameter, Item, is the data type of the items in the Queue.
//   It may be any of the C++ built-in types (int, char, etc.), or a class with
//   a default constructor, a copy constructor, and assignment operator.
//
// CONSTRUCTOR for the List<Item> template class:
//   List( )
//     Postcondition: The List has been initialized as an empty List.
//
// MODIFICATION MEMBER FUNCTIONS for the List<Item> template class:
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted at the head of the
//     List.
//
//   Item get_front( )
//     Precondition: size( ) > 0.
//     Postcondition: The front item of the List is copied and returned.
//
//   void delete_front( )
//     Precondition: size( ) > 0
//     Postcondition: the front item of the List is removed.
//
// CONSTANT MEMBER FUNCTIONS for the List<Item> template class:
//   size_t size( ) const
//     Postcondition: The return value is the total number of items in the List.
//
//   bool is_empty( ) const
//     Postcondition: The return value is true if the List is empty.
//
// VALUE SEMANTICS for the List<Item> template class:
//   Assignments and the copy constructor may be used with List<Item> objects.

#ifndef LIST1_H      // Prevent duplicate definition
#define LIST1_H
#include <stdlib.h>  // Provides size_t
#include <assert.h>  // Provides assert
#ifdef __cplusplus
#include <cstddef>  // Provides NULL
#else
#inlcude <cstddef.h>
#endif
#include "Node1.h"
template <typename T>
class List
{
    private:

    // the node is the place we put our data.  It can be created using
    // the instantiation list method, allowing a quick assignment of
    // passed values

    node<T>* head;		// our head pointer
    size_t count;	// our current size


public:

    // CONSTRUCTOR

    List() : head( NULL ) {}	// uses an instantiation list to set NULL

    // INSPECTORS 

    bool is_empty() const { return ( count == 0 ) ; }
    size_t size() const { return count ; }
	//this function was added to allow access to the head as a node pointer to support iterator operations
	node<T>* get_head(void);

    // MODIFIERS

    void insert(T);
    T& get_front();
	void delete_front();


    // DESTRUCTOR
 
    ~List()
    {
        while(head)
        {
            node<T>* temp(head);	// takes the leading object
            head=head->link();		// repoints to the next
            delete temp;			// deletes the leading object
        }
    }

};

template <typename T>
void List<T>::insert(T data)
{
    head = new node(data, head);	// headptr gets a value based on a new node
    size++;				// incr size, always

}

template<typename T>
void List<T>::delete_front()
{
    assert( is_empty() );		// check to see that we have values

    node* temp(head);			// save the front
    head = head->next ;			// skip headptr over to #2
    delete temp;			// delete the front item

}

template<typename T>
T& List<T>::get_front()
{
    assert( is_empty() );		// check to see that we have values
    return head;			// return it
}

template<typename T>
node<T>* List<T>::get_head(void)
{
	return head;
}
#endif //LIST1_H
