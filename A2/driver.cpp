#include <iostream>

#include "Stack.h"
#include "Fixed_Array.h"
#include "Queue.h"

int main()
{   
    Queue<int>* potato = new Queue<int>;
    
    potato->enqueue(1);
    potato->enqueue(2);
    potato->enqueue(3);
    potato->enqueue(4);
    potato->enqueue(5);
 
    Queue<int>* potato2 = new Queue<int>(*potato);

    std::cout << potato2->dequeue() << std::endl;
    std::cout << potato2->dequeue() << std::endl;
    std::cout << potato2->dequeue() << std::endl;
    std::cout << potato2->dequeue() << std::endl;
    std::cout << potato2->dequeue() << std::endl;

    delete potato;
    delete potato2;
    return 0;
}
