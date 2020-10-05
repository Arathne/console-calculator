#include "Negate_Node.h"
#include <iostream>

Negate_Node::Negate_Node (Node & child) :
    child_(&child)
{}

Negate_Node::~Negate_Node (void) {}

Node & Negate_Node::child (void) const
{
    return *child_;
}

int Negate_Node::evaluate (void)
{
    Negation negate_cmd;
    int result = 0;
    
    result = child_-> evaluate();
    result = negate_cmd.calculate( result );
    
    return result;
}

void Negate_Node::accept (Visitor & v)
{
    v.visit( *this );
}
