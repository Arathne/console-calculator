#include "Expression_Director.h"
#include <iostream>


Expression_Director::Expression_Director (std::stringstream & postfix)    
{
    std::string current;
    
    while( postfix >> current )
    {
        if( current == "+" )
            tree_.build_add();

        else if( current == "-" )
            tree_.build_subtract();
        
        else if( current == "*" )
            tree_.build_multiply();
        
        else if( current == "/" )
            tree_.build_divide();
        
        else if( current == "%" )
            tree_.build_modulus();

        else
        {
            int number;
            std::stringstream strToNumber(current);
            strToNumber >> number;
            
            tree_.build_number(number);
        }
    }
}

Expression_Director::~Expression_Director (void) {}

Node* Expression_Director::get_tree (void)
{
    return tree_.get_tree();
}
