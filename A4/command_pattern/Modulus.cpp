#include "Modulus.h"


Modulus::Modulus (void) :
    level_(2),
    state_(0)
{}

Modulus::~Modulus (void) {}

std::string Modulus::get_string (void) const
{
    return "%";
}

int Modulus::calculate (int num1, int num2)
{
    if( num2 == 0 )
        throw std::runtime_error( "cannot divide by 0 (modulus)" );
    
    state_ = num1 % num2;
    return state_;
}

int Modulus::level (void) const
{
    return level_;
}

int Modulus::precedence (Operator & op) const
{
    return level_ - op.level();   
}

int Modulus::state (void) const
{
    return state_;
}

void Modulus::execute (Stack<int> & stack)
{
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();
    
    Modulus::calculate( num1, num2 ); 
    stack.push( state_ );
}
