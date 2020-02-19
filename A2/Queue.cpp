//=======================================================================
// Honor Pledge
//
// I pledge that I have neither given nor received any help
// on this assignment.
//=======================================================================

#define EMPTY 0
#define FIRST_ELEMENT 0

//
// default constuctor
//
template <typename T>
Queue <T>::Queue( void ):
    size_( EMPTY ),
    data_( new Array <T>( EMPTY ) )
{}

//
// copy constructor
//
template <typename T>
Queue <T>::Queue( const Queue & q ):
    Queue<T> {}
{
    *this = q;
}

//
// destructor
//
template <typename T>
Queue <T>::~Queue( void )
{
    delete data_;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if( &rhs != &(*this) ) // check self comparison
    {
        *data_ = *rhs.data_;
        size_ = rhs.size_;
    }

    return *this;
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue( T element )
{
    size_++;
    data_-> resize( size_ );
    data_-> set( size_-1, element );
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue( void )
{
    if( is_empty() )
    {
        throw empty_exception();
    }

    T content = data_-> get( FIRST_ELEMENT );
    shift_left();
    size_--;

    return content;
}

//
// clear
//
template <typename T>
void Queue <T>::clear( void )
{
    size_ = 0;
}
