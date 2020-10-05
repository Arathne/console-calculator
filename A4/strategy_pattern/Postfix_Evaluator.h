#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include "Expression_Evaluator.h"
#include "../builder_pattern/Expression_Director.h"
#include "../visitor_pattern/Postorder_Traversal.h"

class Postfix_Evaluator : Expression_Evaluator
{
    public:
        Postfix_Evaluator (void);
        ~Postfix_Evaluator (void);
        
        bool is_valid_expression (void) const;
        void parse_expression (std::stringstream & expression);
        int evaluate_expression (void);

    private:
        bool valid_;
        Expression_Director* tree_builder_;
        Postorder_Traversal postfix_;
};

#endif
