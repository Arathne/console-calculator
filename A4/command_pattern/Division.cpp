#include "Division.h"

Division::Division (void) :
    level_(2),
    state_(0)
{}

Division::~Division (void) {}

std::string Division::get_string (void) const
{
    return "/";
}

int Division::calculate (int num1, int num2)
{
    if( num2 == 0 )
        throw std::runtime_error( "cannot divide by 0 (division)" );
    
    state_ = num1 / num2;
    return state_;
}

int Division::level (void) const
{
    return level_;
}

int Division::precedence (Operator & op) const
{
    return level_ - op.level();   
}

int Division::state (void) const
{
    return state_;
}

void Division::execute (Stack<int> & stack)
{
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();
    
    Division::calculate( num1, num2 ); 
    stack.push( state_ );
}
