// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment

template <typename T>
Array <T>::Array (void):
    Array_Base<T>{}
{}

template <typename T>
Array <T>::Array (size_t length):
    Array_Base<T>{ length }
{}

template <typename T>
Array <T>::Array (size_t length, T fill):
    Array_Base<T>{ length, fill }
{}

template <typename T>
Array <T>::~Array ()
{}
