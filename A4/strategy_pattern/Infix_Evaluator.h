#ifndef INFIX_EVALUATOR_H
#define INFIX_EVALUATOR_H

#include "Expression_Evaluator.h"
#include "../builder_pattern/Expression_Director.h"
#include "../visitor_pattern/Postorder_Traversal.h"

#include "Infix_To_Postfix.h"

class Infix_Evaluator : Expression_Evaluator
{
    public:
        Infix_Evaluator (void);
        ~Infix_Evaluator (void);
        
        bool is_valid_expression (void) const;
        void parse_expression (std::stringstream & expression);
        int evaluate_expression (void);

    private:
        bool valid_;
        Expression_Director* tree_builder_;
        Postorder_Traversal postfix_;
};

#endif
