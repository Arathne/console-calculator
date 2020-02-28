#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 0

//
// Array
//
template <typename T>
Array_Base <T>::Array_Base (void):
    data_( new T[ DEFAULT_SIZE ] ),
    cur_size_( DEFAULT_SIZE ),
    max_size_( DEFAULT_SIZE )
{}

//
// Array (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length):
    data_( new T[length] ),
    cur_size_( length ),
    max_size_( length )
{}

//
// Array (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
    data_( new T[length] ),
    cur_size_( length ),
    max_size_( length )
{
    Array_Base <T>::fill( fill );
}

//
// Array (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array):
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
Array_Base <T>::~Array_Base (void)
{
    delete[] this-> data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
    if( &rhs != &(*this) )
    {
        Array_Base::resize( rhs.size() );

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
T & Array_Base <T>::operator [] (size_t index)
{
    checkBounds( index );
    return *( data_+index );
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    checkBounds( index );
    return *( data_+index );
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    checkBounds( index );
    return *( data_+index );
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    checkBounds( index );
    *( data_+index ) = value;
}

//
// resize
//
template <typename T>
void Array_Base <T>::resize (size_t new_size)
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
int Array_Base <T>::find (T value) const
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
int Array_Base <T>::find (T val, size_t start) const
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
bool Array_Base <T>::operator == (const Array_Base & rhs) const
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
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    return !( *this == rhs );
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for( int i = 0; i < cur_size_; i++ )
    {
        *( data_+i ) = value;
    }
}

//
// checkBounds
//
template <typename T>
inline
void Array_Base <T>::checkBounds( size_t index ) const
{
    if( index >= cur_size_ )
    {
        throw std::out_of_range( "index out of bounds" );
    }
}
