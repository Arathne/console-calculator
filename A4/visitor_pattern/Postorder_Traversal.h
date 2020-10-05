#ifndef POSTORDER_TRAVERSAL_H
#define POSTORDER_TRAVERSAL_H

#include "../command_pattern/Binary.h"
#include "Visitor.h"
#include "../command_pattern/Math.h"

class Postorder_Traversal : public Visitor
{
    public:
        Postorder_Traversal (void);
        ~Postorder_Traversal (void);

        void visit (Addition_Node & node);
        void visit (Number_Node & node);
        void visit (Subtraction_Node & node);
        void visit (Multiplication_Node & node);
        void visit (Division_Node & node);
        void visit (Modulus_Node & node);
        void visit (Negate_Node & node);
        
        int result (void) const;

    private:
        Math math_;
        int left_;
        int right_;
        int result_;
};

#endif
