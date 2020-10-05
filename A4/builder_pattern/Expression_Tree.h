#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "Expression_Builder.h"
#include "../data_structures/Stack.h"
#include "../visitor_pattern/Postorder_Deletion.h"

class Expression_Tree : public Expression_Builder
{
    public:
        Expression_Tree (void);
        ~Expression_Tree (void);
        
        void build_number (int n);
        void build_add (void);
        void build_subtract (void);
        void build_multiply (void);
        void build_divide (void);
        void build_modulus (void);
        void build_negate (void);
        
        Node* get_tree (void);
        void check_stack (void);

    private:
        Stack<Node*> stack_;
        Node* tree_;

};

#endif
