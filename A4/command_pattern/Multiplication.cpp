#include "Multiplication.h"

Multiplication::Multiplication (void) :
    level_(2),
    state_(0)
{}

Multiplication::~Multiplication (void) {}

std::string Multiplication::get_string (void) const
{
    return "*";
}

int Multiplication::calculate (int num1, int num2)
{
    state_ = num1 * num2;
    return state_;
}

int Multiplication::level (void) const
{
    return level_;
}

int Multiplication::precedence (Operator & op) const
{
    return level_ - op.level();   
}

int Multiplication::state (void) const 
{
    return state_;
}

void Multiplication::execute (Stack<int> & stack)
{
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();

    Multiplication::calculate( num1, num2 ); 
    stack.push( state_ );
}
