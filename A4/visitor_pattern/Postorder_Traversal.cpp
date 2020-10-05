#include "Postorder_Traversal.h"

#include <iostream>

Postorder_Traversal::Postorder_Traversal (void) :
    result_(0),
    left_(0),
    right_(0)
{}

Postorder_Traversal::~Postorder_Traversal (void) {}

int Postorder_Traversal::result (void) const
{
    return result_;
}

void Postorder_Traversal::visit( Number_Node & node )
{
    result_ = node.evaluate();
}

void Postorder_Traversal::visit( Addition_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    left_ = result_;
    
    int temp = left_;

    rightNode-> accept(*this);
    right_ = result_;
    
    result_ = math_.add(temp, right_);
}

void Postorder_Traversal::visit( Subtraction_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    left_ = result_;
    
    int temp = left_;

    rightNode-> accept(*this);
    right_ = result_;
    
    result_ = math_.subtract(temp, right_);
}

void Postorder_Traversal::visit( Multiplication_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    left_ = result_;
    
    int temp = left_;

    rightNode-> accept(*this);
    right_ = result_;
    
    result_ = math_.multiply(temp, right_);
}

void Postorder_Traversal::visit( Division_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    left_ = result_;
    
    int temp = left_;

    rightNode-> accept(*this);
    right_ = result_;
    
    result_ = math_.divide(temp, right_);
}

void Postorder_Traversal::visit( Modulus_Node & node )
{
    Node* leftNode = &(node.left());
    Node* rightNode = &(node.right());
    
    leftNode-> accept(*this);
    left_ = result_;
    
    int temp = left_;

    rightNode-> accept(*this);
    right_ = result_;
    
    result_ = math_.modulus(temp, right_);
}

void Postorder_Traversal::visit( Negate_Node & node )
{
    Node* childNode = &(node.child());
    childNode-> accept(*this);
    
    result_ = math_.negate(result_);
}
