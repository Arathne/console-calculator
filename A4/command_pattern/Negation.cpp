#include "Negation.h"

Negation::Negation (void) :
    level_(3),
    state_(0)
{}

Negation::~Negation (void) {}

std::string Negation::get_string (void) const
{
    return "?";
}

int Negation::precedence (Operator & op) const 
{
    return level_ - op.level();   
}

int Negation::level (void) const 
{
    return level_;
}

int Negation::calculate (int number)
{
    state_ = number * -1;
    return state_;
}

int Negation::state (void) const
{
    return state_;
}

void Negation::execute (Stack<int> & stack)
{
    int num = stack.top();
    stack.pop();
    
    Negation::calculate( num ); 
    stack.push( state_ );
}
