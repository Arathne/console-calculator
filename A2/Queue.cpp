//=======================================================================
// Honor Pledge
//
// I pledge that I have neither given nor received any help
// on this assignment.
//=======================================================================

#define EMPTY 0

//
// default constuctor
//
template <typename T>
Queue <T>::Queue( void ):
    start_( EMPTY ),
    end_( EMPTY+1 ),
    data_( Array <T>( EMPTY ) )
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
Queue <T>::~Queue( void ) {}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    if( &rhs != &(*this) ) // check self comparison
    {
        data_ = rhs.data_;
        start_ = rhs.start_;
        end_ = rhs.end_;
    }

    return *this;
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue( T element )
{
    if( end_ > data_.size() ) // only resize data_ when necessary
        data_.resize( end_ );
    
    data_.set( end_-1, element );
    end_++;
}

// COMMENT This design is OK, but it is not the best design. This will be
// a very expensive array to use if you are dequeing a lot of elements. This
// is because you are copying N elements each time you dequeue 1 element.
// Instead, you only want to copy element when necessary. Come up with a better
// design that is not as expensive for the client to use.
//
// UPDATE only reallocates data when array is getting larger. When queue is empty,
// it will start at the beginning
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
    
    T element = data_.get( start_ );
    start_++;
    
    if( is_empty() ) // start at beginning when empty to prevent reallocation
    {
        clear();      
    }

    return element;
}

//
// clear
//
template <typename T>
void Queue <T>::clear( void )
{
    start_ = EMPTY;
    end_ = EMPTY+1;
}
