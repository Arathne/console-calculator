// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
// Edgar Torrez
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <iostream>

/* UPDATE
 * now uses base member initialization instead of using assignment operators
*/
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
Array::Array (void):
    data_( new char[10] ),
    cur_size_(10),
    max_size_(10)
{}


/* UPDATE
 * now uses base member initialization instead of using assignment operators
*/
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
Array::Array (size_t length):
    data_( new char[length] ),
    cur_size_(length),
    max_size_(length)
{}
    

/* UPDATE
 * now uses base member initialization instead of using assignment operators
*/
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
Array::Array (size_t length, char fill):
    data_( new char[length] ),
    cur_size_(length),
    max_size_(length)
{
    Array::fill( fill );
}


/* UPDATE
 * now uses base member initialization and added a
 * for loop to deep copy properly
*/
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// 
// COMMENT The copy constructor needs to create a deep copy of the source array.
Array::Array (const Array & array): 
    data_( new char[array.size()] ),
    cur_size_( array.size() ),
    max_size_( array.size() )
{
	for( int i = 0; i < array.size(); i++ )
	{
		*( data_+i ) = array.get(i);
	}
}    


Array::~Array (void)
{
	delete[] this-> data_;
}


/* UPDATE
 * now checks for self assignment and reallocates memory when needed
 * -- most of method has been changed
*/
// COMMENT Check for self assignment first.
// 
// COMMENT You should only change the allocation size of this array is not
// large enough to hold rhs.
const Array & Array::operator = (const Array & rhs)
{
    if( &rhs != &(*this) ) // checks for self comparison
    {
        Array::resize( rhs.size() ); // decide if reallocation is needed
                  
	    for( int i = 0; i < cur_size_; i++ ) // copy data from rhs to data_
	    {
		    *( data_+i ) = rhs.get(i);
	    }
    }

	return *(this);
}

char & Array::operator [] (size_t index)
{
	checkBounds( index );
	return *( data_+index );
}	

const char & Array::operator [] (size_t index) const
{
	checkBounds( index );
	return *( data_+index );
}

char Array::get (size_t index) const
{
	checkBounds( index );
	return *( data_+index );
}

void Array::set (size_t index, char value)
{	
	checkBounds( index );
	*( data_+index ) = value;
}

/* UPDATE
 * saves pointer containing old data and deletes it when finished
*/
// COMMENT Make sure the array owns the new data pointer before you delete
// the old data pointer.
void Array::resize (size_t new_size)
{
	if( new_size < max_size_ )
	{
		this-> cur_size_ = new_size;
	}
	else if( new_size > max_size_ )
	{
		char* temp = new char[ new_size ];

		for( int i = 0; i < max_size_; i++ ) // copy data_ into a temporary char array with different size
		{
			*( temp+i ) = *( data_+i );
		}
        
        char* old_pointer = this-> data_;

        this-> data_ = temp;
		this-> max_size_ = new_size;
		this-> cur_size_ = this-> max_size_;
        
        delete[] old_pointer;
	}
}

/* UPDATE
 * copied the other find method, removed checkBounds method, and 
 * initialized i to 0
*/
// COMMENT Using find with index is good, but it will throw an exception is certain cases.
// The find with no index should not throw an exception.
int Array::find (char ch) const
{
	bool run = true;
	int i = 0;
	int position = -1;

	while( run )
	{	
		if( i >= cur_size_ ) //exit once you go through entire array
		{
			run = false;
		}
		else if( *( data_+i ) == ch ) //exit once you find a match
		{
			position = i;
			run = false;
		}

		i++;
	}
	return position;
}


/* UPDATE
 * only deleted the if statement around checkBounds
 */
// COMMENT This will have the wrong behavior of the array size is 0, and the
// caller invokes find with a start index of 0. In that case, an exception
// should be thrown since 0 is out of range.
int Array::find (char ch, size_t start) const
{
    checkBounds( start );

	bool run = true;
	int i = start;
	int position = -1;

	while( run )
	{	
		if( i >= cur_size_ ) //exit once you go through entire array
		{
			run = false;
		}
		else if( *( data_+i ) == ch ) //exit once you find a match
		{
			position = i;
			run = false;
		}

		i++;
	}
	return position;
}

/* UPDATE
 * added if statement to check for self comparison
*/
// COMMENT Check for self comparison first.
bool Array::operator == (const Array & rhs) const
{
    bool equal = true;
    if( &rhs != &(*this) ) // checks for self comparison
    {
        bool run = true;
	    int i = 0;

	    if( this-> cur_size_ != rhs.size() )
	    {
		    equal = false;
		    run = false; //no need to check if char arrays are equal
	    }

	    while( run )
	    {	
		    if( i >= cur_size_ ) //exit once you go through entire array
		    {
			    run = false;
		    }
		    else if( *( data_+i ) != rhs.get(i) ) //exit once you find out they dont match
		    {
			    equal = false;
			    run = false;
		    }

		    i++;
	    }
    }

	return equal;
}

bool Array::operator != (const Array & rhs) const
{
	return !( *this == rhs );
}

void Array::fill (char ch)
{
	for( int i = 0; i < cur_size_; i++ )
	{
		*( data_+i ) = ch;
	}
}

/* UPDATE
 * pretty sure I don't have to change anything since that's what it does
*/
// how does one shrink something to reclaim unused space... makes no sense
// i'm just going guess...
// i'm assuming you want it to reclaim space
//
// COMMENT Purpose of the shrink method is to recover an unused
// memory allocation. For example, if the array has allocated 10, and
// the current size is 5, then 5 spaces us wasted. The shrink method
// we reclaim the 5 unused spaces so the array only has an allocation
// large enough to fits is current size (i.e., 5 in this example).
void Array::shrink (void)
{
	this-> cur_size_ = this-> max_size_;	
}

void Array::reverse (void)
{
	for( int i = 0; i <= cur_size_/2; i++ ) // go through half the array
	{
		char temp = *( data_+i );  // swap left with right
		*( data_+i ) = *( data_+cur_size_-1-i );
		*( data_+cur_size_-1-i ) = temp;
	}
}

Array Array::slice (size_t begin) const
{	
	return Array::slice( begin, cur_size_ );
}

Array Array::slice (size_t begin, size_t end) const
{
	Array sliced(0);

	if( begin >= 0 && begin < cur_size_ ) // make sure 'begin' is within array
	{
        if( end <= cur_size_ ) // 'end' cannot be greater than current array
        {
		    size_t length = end - begin;
		    sliced.resize( length );

		    for( int i = 0; i < length; i++ ) // copy requested data into sliced
		    {
			    sliced[i] = *( data_+i+begin );
		    }
        }
	}
	
	return sliced;
}

