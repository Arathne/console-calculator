#include <iostream>

//#include "Queue.h"
#include "Stack.h"
#include "Fixed_Array.h"

int main()
{   
    Stack<int>* potato = new Stack<int>;
    potato-> push( 10 );
    std::cout << potato-> top() << std::endl;
    potato-> push( 5 );
    
    Stack<int>* potato2 = new Stack<int>(*potato);

    std::cout << potato-> top() << std::endl;
    potato-> pop();
    std::cout << potato-> size() << std::endl;   
    std::cout << potato2-> size() << std::endl;   
    

    delete potato;
    return 0;
}
