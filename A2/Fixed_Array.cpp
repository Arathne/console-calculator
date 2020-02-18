// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $
#include <iostream>
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):
    Array<T>{ N }
{}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr):
    Array<T>{ arr }
{}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr):
    Array<T>{ N }
{
    *this = arr;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):
    Array<T>{ N, fill }
{}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    if( rhs != *this ) // check self-comparison
    {
        for( int i = 0; i < N; i++ ) // copy rhs to lhs
        {
            Fixed_Array<T,N>::set( i, rhs.get(i) );
        }
    }
    
    return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    if( rhs != *this ) // check self-comparison
    {
        size_t smallestSize = N; // find smallest array size
        if( rhs.size() < N )
        {
            smallestSize = rhs.size();
        }

        for( int i = 0; i < smallestSize; i++ ) // copy rhs to lhs
        {
            Fixed_Array<T,N>::set( i, rhs.get(i) );
        }
    }
    
    return *this;
}
