#ifndef POSTORDER_DELETION_H
#define POSTORDER_DELETION_H

#include "../command_pattern/Binary.h"
#include "Visitor.h"
#include "../command_pattern/Math.h"

class Postorder_Deletion : public Visitor
{
    public:
        Postorder_Deletion (void);
        ~Postorder_Deletion (void);

        void visit (Addition_Node & node);
        void visit (Number_Node & node);
        void visit (Subtraction_Node & node);
        void visit (Multiplication_Node & node);
        void visit (Division_Node & node);
        void visit (Modulus_Node & node);
        void visit (Negate_Node & node);
};

#endif
