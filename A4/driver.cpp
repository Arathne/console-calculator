#include <iostream>
#include <sstream>

#include <string>
#include <sstream>

#include "strategy_pattern/Infix_Evaluator.h"

int main()
{   
    bool run = true;

    while( run )
    {
        std::cout << "?: ";

        std::string input = "";
        std::getline( std::cin, input );

        if( input == "QUIT" )
            run = false;
        else
        {
            std::stringstream infix(input);
            
            Infix_Evaluator expression;
            expression.parse_expression(infix);
            
            if( expression.is_valid_expression() )
            {
                int result = expression.evaluate_expression();
                std::cout << result << std::endl;
            }
            else
            {
                std::cout << "expression is invalid" << std::endl;
            }
        }
    }
    
    return 0;
}
