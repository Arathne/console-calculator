#include "Expression_Tree.h"

Expression_Tree::Expression_Tree (void) :
    tree_(nullptr)
{}

Expression_Tree::~Expression_Tree (void) 
{
    Postorder_Deletion tree_deletion;
    while( !stack_.is_empty() )
    {
        stack_.top() -> accept(tree_deletion);
        stack_.pop();
    }
}

Node* Expression_Tree::get_tree (void)
{
    return tree_;
}

void Expression_Tree::build_number (int number) 
{
    Node* numNode = new Number_Node(number);
    stack_.push( numNode );
}

void Expression_Tree::build_add (void) 
{
    check_stack();
    Node* item1 = stack_.top();
    stack_.pop();
    
    check_stack();
    Node* item2 = stack_.top();
    stack_.pop();
    
    Node* resultNode = new Addition_Node(*item2, *item1);
    stack_.push( resultNode );
    
    tree_ = resultNode;
}

void Expression_Tree::build_subtract (void)
{
    check_stack();
    Node* item1 = stack_.top();
    stack_.pop();
    
    check_stack();
    Node* item2 = stack_.top();
    stack_.pop();
    
    Node* resultNode = new Subtraction_Node(*item2, *item1);
    stack_.push( resultNode );
    
    tree_ = resultNode;
}

void Expression_Tree::build_multiply (void) 
{
    check_stack();
    Node* item1 = stack_.top();
    stack_.pop();
    
    check_stack();
    Node* item2 = stack_.top();
    stack_.pop();
    
    Node* resultNode = new Multiplication_Node(*item2, *item1);
    stack_.push( resultNode );
    
    tree_ = resultNode;
}

void Expression_Tree::build_divide (void) 
{
    check_stack();
    Node* item1 = stack_.top();
    stack_.pop();
    
    check_stack();
    Node* item2 = stack_.top();
    stack_.pop();
    
    Node* resultNode = new Division_Node(*item2, *item1);
    stack_.push( resultNode );
    
    tree_ = resultNode;
}

void Expression_Tree::build_modulus (void) 
{
    check_stack();
    Node* item1 = stack_.top();
    stack_.pop();
    
    check_stack();
    Node* item2 = stack_.top();
    stack_.pop();
    
    Node* resultNode = new Modulus_Node(*item2, *item1);
    stack_.push( resultNode );
    
    tree_ = resultNode;
}

void Expression_Tree::build_negate (void) 
{
    check_stack();
    Node* item1 = stack_.top();
    stack_.pop();
    
    Node* resultNode = new Negate_Node(*item1);
    stack_.push( resultNode );
    
    tree_ = resultNode;
}

void Expression_Tree::check_stack (void)
{
    if( stack_.is_empty() )
        throw std::runtime_error( "cannot perform operation because stack is empty" );
}
