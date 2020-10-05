// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#define EMPTY 0

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
    size_( EMPTY ),
    data_( Array<T>( EMPTY ) )
{}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
    Stack<T>{}
{
    *this = stack;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void) {}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    size_++;
    data_.resize( size_ );
    data_.set( size_-1, element );
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if( is_empty() )
    {
        throw empty_exception();
    }

    size_--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{  
    if( &rhs != &(*this) ) // check self comparison
    {
        data_ = rhs.data_;
        size_ = rhs.size_;
    }

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    data_-> resize( EMPTY );      
    size_ = EMPTY;
}
