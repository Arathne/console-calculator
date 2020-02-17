// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void):
    data_( new T[0] ),
    cur_size_( 0 ),
    max_size_( 0 )
{}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
    data_( new T[length] ),
    cur_size_( length ),
    max_size_( length )
{}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
    data_( new T[length] ),
    cur_size_( length ),
    max_size_( length )
{
    Array <T>::fill( fill );
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
    data_( new T[array.size()] ),
    cur_size_( array.size() ),
    max_size_( array.size() )
{
    for( int i = 0; i < array.size(); i++ )
    {
        *( data_+i ) = array.get(i);
    }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    delete[] this-> data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if( &rhs != &(*this) )
    {
        Array::resize( rhs.size() );

        for( int i = 0; i < cur_size_; i++ )
        {
            *( data_+i ) = rhs.get(i);
        }
    }

    return *(this);
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
    checkBounds( index );
    return *( data_+index );
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    checkBounds( index );
    return *( data_+index );
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
    checkBounds( index );
    return *( data_+index );
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
    checkBounds( index );
    *( data_+index ) = value;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if( new_size < max_size_ )
    {
        this-> cur_size_ = new_size;
    }
    else if( new_size > max_size_ )
    {
        T* temp = new T[ new_size ];

        for( int i = 0; i < max_size_; i++ )
        {
            *( temp+i ) = *( data_+i );
        }
    
        T* old_pointer = this-> data_;

        this-> data_ = temp;
        this-> max_size_ = new_size;
        this-> cur_size_ = this-> max_size_;

        delete[] old_pointer;
    }
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
    bool run = true;
    int i = 0;
    int position = -1;

    while( run )
    {
        if( i >= cur_size_ )
        {
            run = false;
        }
        else if( *( data_+i ) == value )
        {
            position = i;
            run = false;
        }

        i++;
    }
    return position;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
    checkBounds( start );

    bool run = true;
    int i = start;
    int position = -1;

    while( run )
    {
        if( i >= cur_size_ )
        {
            run = false;
        }
        else if( *( data_+i ) == val )
        {
            position = i;
            run = false;
        }

        i++;
    }
    return position;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
    bool equal = true;
    
    if( &rhs != &(*this) )
    {
        bool run = true;
        int i = 0;

        if( this-> cur_size_ != rhs.size() )
        {
            equal = false;
            run =false;
        }

        while( run )
        {
            if( i >= cur_size_ )
            {
                run = false;
            }
            else if( *( data_+i ) != rhs.get(i) )
            {
                equal = false;
                run = false;
            }

            i++;
        }
    }

    return equal;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
    return !( *this == rhs );
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
    for( int i = 0; i < cur_size_; i++ )
    {
        *( data_+i ) = value;
    }
}
