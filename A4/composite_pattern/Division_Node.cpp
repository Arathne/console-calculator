#include "Division_Node.h"


Division_Node::Division_Node (Node & left, Node & right) :
    left_(&left),
    right_(&right)
{}

Division_Node::~Division_Node (void) {}

Node & Division_Node::right (void) const
{
    return *right_;
}

Node & Division_Node::left (void) const
{
    return *left_;
}

int Division_Node::evaluate (void)
{
    Division command;

    int resultRight = right_-> evaluate();
    int resultLeft = left_-> evaluate();
    
    return command.calculate( resultLeft, resultRight );
}

void Division_Node::accept (Visitor & v)
{
    v.visit( *this );
}
