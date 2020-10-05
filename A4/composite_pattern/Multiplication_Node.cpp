#include "Multiplication_Node.h"


Multiplication_Node::Multiplication_Node (Node & left, Node & right) :
    left_(&left),
    right_(&right)
{}

Multiplication_Node::~Multiplication_Node (void) {}

Node & Multiplication_Node::right (void) const
{
    return *right_;
}

Node & Multiplication_Node::left (void) const
{
    return *left_;
}

int Multiplication_Node::evaluate (void)
{
    Multiplication command;

    int resultRight = right_-> evaluate();
    int resultLeft = left_-> evaluate();
    
    return command.calculate( resultLeft, resultRight );
}

void Multiplication_Node::accept (Visitor & v)
{
    v.visit( *this );
}
