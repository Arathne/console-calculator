// -*- C++ -*-
// $Id: Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
    return this-> cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
    return this-> max_size_;
}

template <typename T>
inline
void Array_Base <T>::checkBounds( size_t index ) const
{
    if( index >= cur_size_ )
    {
        throw std::out_of_range( "index out of bounds" );
    }
}
