#include "Subtraction_Node.h"


Subtraction_Node::Subtraction_Node (Node & left, Node & right) :
    left_(&left),
    right_(&right)
{}

Subtraction_Node::~Subtraction_Node (void) {}

Node & Subtraction_Node::right (void) const
{
    return *right_;
}

Node & Subtraction_Node::left (void) const
{
    return *left_;
}

int Subtraction_Node::evaluate (void)
{
    Subtraction command;

    int resultRight = right_-> evaluate();
    int resultLeft = left_-> evaluate();
    
    return command.calculate( resultLeft, resultRight );
}

void Subtraction_Node::accept (Visitor & v)
{
    v.visit( *this );
}
