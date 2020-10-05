#include "Infix_Evaluator.h"

Infix_Evaluator::Infix_Evaluator (void) :
    valid_(false),
    tree_builder_(nullptr)
{}

Infix_Evaluator::~Infix_Evaluator (void) 
{
    if( tree_builder_ != nullptr )
        delete tree_builder_;
}

bool Infix_Evaluator::is_valid_expression (void) const
{
    return valid_;
}

void Infix_Evaluator::parse_expression (std::stringstream & expression)
{
    Infix_To_Postfix manager;
    std::string result = manager.convert( expression );

    if( tree_builder_ != nullptr )
        delete tree_builder_;
    
    try
    {
        std::stringstream post( result );
        tree_builder_ = new Expression_Director( post );
        valid_ = true;
    }
    catch( ... )
    {
        valid_ = false;
    }
}

int Infix_Evaluator::evaluate_expression (void)
{
    int result = -1;

    if( valid_ )
    {
        tree_builder_->get_tree()  -> accept( postfix_ );
        result = postfix_.result();
    }

    return result;
}
