#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include <sstream>

class Expression_Evaluator
{
    public:
        virtual ~Expression_Evaluator (void) {};
        
        virtual bool is_valid_expression (void) const = 0;
        virtual void parse_expression (std::stringstream & expression) = 0;
        virtual int evaluate_expression (void) = 0;
};

#endif
