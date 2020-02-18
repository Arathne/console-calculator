// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    return data_-> get( size_-1 );
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    bool empty = false;
    
    if( size_ == 0 )
    {
        empty = true;
    }
    
    return empty;
}
