#include "Postfix_Evaluator.h"


Postfix_Evaluator::Postfix_Evaluator (void) :
    valid_(false),
    tree_builder_(nullptr)
{}

Postfix_Evaluator::~Postfix_Evaluator (void) 
{
    if( tree_builder_ != nullptr )
        delete tree_builder_;
}

bool Postfix_Evaluator::is_valid_expression (void) const
{
    return valid_;
}

void Postfix_Evaluator::parse_expression (std::stringstream & expression)
{
    if( tree_builder_ != nullptr )
        delete tree_builder_;
    
    try
    {
        tree_builder_ = new Expression_Director(expression);
        valid_ = true;
    }
    catch( ... )
    {
        valid_ = false;
    }
}

int Postfix_Evaluator::evaluate_expression (void)
{
    int result = -1;

    if( valid_ )
    {
        tree_builder_->get_tree()  -> accept( postfix_ );
        result = postfix_.result();
    }

    return result;
}
