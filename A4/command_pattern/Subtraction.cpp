#include "Subtraction.h"


Subtraction::Subtraction (void) :
    level_(1),
    state_(0)
{}

Subtraction::~Subtraction (void) {}

std::string Subtraction::get_string (void) const
{
    return "-";
}

int Subtraction::calculate (int num1, int num2)
{
    state_ = num1 - num2;
    return state_;
}

int Subtraction::level (void) const
{
    return level_;
}

int Subtraction::precedence (Operator & op) const
{
    return level_ - op.level();   
}

int Subtraction::state (void) const
{
    return state_;
}

void Subtraction::execute (Stack<int> & stack)
{
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();
    
    Subtraction::calculate( num1, num2 ); 
    stack.push( state_ );
}
