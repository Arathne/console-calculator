//=================================================================
// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
//=================================================================

//
// size
//
template <typename T>
inline
size_t Queue <T>::size( void ) const
{
    return size_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty( void ) const
{
    bool empty = false;

    if( size_ == 0 )
    {
        empty = true;
    }

    return empty;
}

//
// shift_left
//
/**
 * this assumes memory allocation is more expensive than shifting the
 * elements to the left.
 * 
 * helps removing dead space at the front of the queue that may never be used
 * and keeps memory use minimal.
 */
template <typename T>
inline
void Queue <T>::shift_left( void )
{
    if( size_ > 1 ) //must have at least 2 elements for a shift
    {
        for( int i = 1; i < size_; i++ )
        {
            T content = data_->get( i );
            data_-> set( i-1, content );
        }
    }
}
