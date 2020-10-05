#include "Modulus_Node.h"


Modulus_Node::Modulus_Node (Node & left, Node & right) :
    left_(&left),
    right_(&right)
{}

Modulus_Node::~Modulus_Node (void) {}

Node & Modulus_Node::right (void) const
{
    return *right_;
}

Node & Modulus_Node::left (void) const
{
    return *left_;
}

int Modulus_Node::evaluate (void)
{
    Modulus command;

    int resultRight = right_-> evaluate();
    int resultLeft = left_-> evaluate();
    
    return command.calculate( resultLeft, resultRight );
}

void Modulus_Node::accept (Visitor & v)
{
    v.visit( *this );
}
