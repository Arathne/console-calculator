#include "Addition_Node.h"

#include <iostream>

Addition_Node::Addition_Node (Node & left, Node & right) :
    left_(&left),
    right_(&right)
{}

Addition_Node::~Addition_Node (void) {}

Node & Addition_Node::right (void) const
{
    return *right_;
}

Node & Addition_Node::left (void) const
{
    return *left_;
}

int Addition_Node::evaluate (void)
{
    Addition command;

    int resultRight = right_-> evaluate();
    int resultLeft = left_-> evaluate();
    std::cout << "resultRight : " << resultRight << std::endl;   
    std::cout << "resultLeft : " << resultLeft << std::endl;   
    return command.calculate( resultLeft, resultRight );
}

void Addition_Node::accept (Visitor & v)
{
    v.visit( *this );
}

/*Addition_Node & Addition_Node::operator = (const Addition_Node & rhs)
{
    if( &rhs != &(*this) ) // check self comparison
    {
        left_ = rhs.left_;
        right_ = rhs.right_;
    }

    return *this;
}*/
