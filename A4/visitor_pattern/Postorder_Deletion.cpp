#include "Postorder_Deletion.h"

#include <iostream>

Postorder_Deletion::Postorder_Deletion (void) {}

Postorder_Deletion::~Postorder_Deletion (void) {}

void Postorder_Deletion::visit( Number_Node & node )
{
    delete &node;
}

void Postorder_Deletion::visit( Addition_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    rightNode-> accept(*this);
    
    delete &node;
}

void Postorder_Deletion::visit( Subtraction_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    rightNode-> accept(*this);
    
    delete &node;
}

void Postorder_Deletion::visit( Multiplication_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    rightNode-> accept(*this);
    
    delete &node;
}

void Postorder_Deletion::visit( Division_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    rightNode-> accept(*this);
    
    delete &node;
}

void Postorder_Deletion::visit( Modulus_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    rightNode-> accept(*this);
    
    delete &node;
}

void Postorder_Deletion::visit( Negate_Node & node )
{
    Node* childNode = &(node.child());
    childNode-> accept(*this);
    
    delete &node;
}
