// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

inline
size_t Array::size (void) const
{
	return this-> cur_size_;
}

inline
size_t Array::max_size (void) const
{
	return this-> max_size_;
}

/* UPDATE
 * removed index < 0 in if statement
 * because size_t can't be less than 0
*/
// COMMENT size_t can never be less than 0
inline
void Array::checkBounds( size_t index ) const
{
	if ( index >= cur_size_ )
	{		
		throw std::out_of_range( "index out of bounds" );
	}
}
