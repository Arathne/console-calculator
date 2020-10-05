#include "Number.h"


Number::Number (void) :
    state_(0)
{};

Number::Number (int number) :
    state_(number)
{}

Number::~Number (void) {}

void Number::execute (Stack<int> & stack)
{
    state_ = stack.top();
    stack.pop();
}

int Number::state (void) const
{
    return state_;
}
