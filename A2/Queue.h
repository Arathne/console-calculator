//====================================================================
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
//====================================================================

#ifndef _CS507_QUEUE_H_  // for consistency
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"
#include <iostream>

template <typename T>
class Queue
{
public:
    typedef T type;
    
    /**
     * @class empty_exception
     *
     * exception thrown to indicate the stack is empty
     *
     */
    class empty_exception : public std::exception
    {
    public:
        empty_exception( void ):
            std::exception() {}

        empty_exception( const char* msg ):
            std::exception( msg ) {}
    };


    //default constructor
    Queue( void );

    //copy constructor
    Queue( const Queue & q );
    
    // destructor
    ~Queue( void );
    
    /** 
     * assignment operator
     *
     * @param[in]       rhs         right-hand side of operator
     * @return          reference to self
     */
    const Queue & operator = (const Queue & rhs);

    /**
     * adds the element to the end of the list
     *
     * @param[in]       element     element to add to the list
     */
    void enqueue( T element );
    
    /**
     * removes element from the front of the list
     *
     * @return          returns the front element
     *
     * @exception       empty_exception     Queue is empty
     */
    T dequeue( void );

    /**
     * number of elements on the stack
     *
     * @return          returns number of elements in the queue
     */
    size_t size( void ) const;
    
    /**
     * removes elements from queue
     */
    void clear( void );

    /**
     * test is the stack is empty
     *
     * @retval          true            the stack is empty
     * @retval          false           the stack is not empty
     */
    bool is_empty( void ) const;

private:
    /**
     * shifts elements to the left by 1 and discards if not possible
     */
    void shift_left( void );
    
    size_t size_;
    Array<T>* data_;
};

#include "Queue.inl"
#include "Queue.cpp"

#endif
