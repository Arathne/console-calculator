#include "Addition.h"


Addition::Addition (void) :
    level_(1),
    state_(0)
{}

Addition::~Addition (void) {}

std::string Addition::get_string (void) const
{
    return "+";
}

int Addition::calculate (int num1, int num2)
{
    state_ = num1 + num2;
    return state_;
}

int Addition::level (void) const
{
    return level_;
}

int Addition::precedence (Operator & op) const
{
    return level_ - op.level();   
}

int Addition::state (void) const
{
    return state_;
}

void Addition::execute (Stack<int> & stack)
{
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();

    Addition::calculate( num1, num2 ); 
    stack.push( state_ );
}
