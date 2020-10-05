#include "Infix_To_Postfix.h"

Infix_To_Postfix::Infix_To_Postfix (void) :
    current_operator_(nullptr)
{}

Infix_To_Postfix::~Infix_To_Postfix (void) {}

std::string Infix_To_Postfix::convert (std::stringstream & infix) 
{
    std::string result;
    std::string current;
    int balance = 0;

    while (infix >> current)
    {
        
        if( current == "+" )
        {
            current_operator_ = new Addition();
            result = check_stack(result);
            operators_.push( current_operator_ );
        }
        else if( current == "-" )
        {
            current_operator_ = new Subtraction();
            result = check_stack(result);
            operators_.push( current_operator_ );
        }
        else if( current == "*" )
        {
            current_operator_ = new Multiplication();
            result = check_stack(result);
            operators_.push( current_operator_ );
        }
        else if( current == "/" )
        {
            current_operator_ = new Division();
            result = check_stack(result);
            operators_.push( current_operator_ );
        }
        else if( current == "%" )
        {
            current_operator_ = new Modulus();
            result = check_stack(result);
            operators_.push( current_operator_ );
        }
        else if( current == "(" )
        {
            balance++;
            
            std::stringstream child_expression;
            child_expression << infix.rdbuf();
            
            Infix_To_Postfix manager;
            result += manager.convert( child_expression );
            infix << child_expression.rdbuf();
        }
        else if( current == ")" )
        { 
            result += operators_in_stack();
        }
        else
        {
           result += " " + current;
        }
    }
    
    result += operators_in_stack();
    
    return result;
}

/**********
 * returns all operators in the stack
*/
std::string Infix_To_Postfix::operators_in_stack (void)
{
    std::string result = "";

    while( !operators_.is_empty() )
    {
        Binary* op = operators_.top();
        result += " " + op-> get_string();
        delete op;
        operators_.pop();
    }

    return result;
}

/**********
 * goes through all operators on the stack and places operators
 * with higher precedence into result
*/
std::string Infix_To_Postfix::check_stack (std::string result)
{
    Stack<Binary*> temp;
    
    while( !operators_.is_empty() )
    {
        Binary* current = operators_.top();
        
        if( current-> precedence( *current_operator_ ) >= 0 )
        {
            result += " " + current-> get_string();
            delete current;
        }
        else
        {
            temp.push( operators_.top() );
        }

        operators_.pop();
    }
    
    while( !temp.is_empty() )
    {
        operators_.push( temp.top() );
        temp.pop();
    }

    return result;
}
