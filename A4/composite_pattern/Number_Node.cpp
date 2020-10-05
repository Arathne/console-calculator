#include "Number_Node.h"

Number_Node::Number_Node (int number) :
    number_(number)
{}

Number_Node::~Number_Node (void) {}

int Number_Node::evaluate (void)
{
    return number_;
}

void Number_Node::accept (Visitor & v)
{
    v.visit( *this );
}

/*Number_Node & Number_Node::operator = (const Number_Node & rhs)
{  
    if( &rhs != &(*this) ) // check self comparison
        number_ = rhs.number_;

    return *this;
}*/
