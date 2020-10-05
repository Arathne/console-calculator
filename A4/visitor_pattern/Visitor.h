#ifndef VISITOR_H
#define VISITOR_H

#include "../composite_pattern/Number_Node.h"
#include "../composite_pattern/Addition_Node.h"
#include "../composite_pattern/Subtraction_Node.h"
#include "../composite_pattern/Multiplication_Node.h"
#include "../composite_pattern/Division_Node.h"
#include "../composite_pattern/Modulus_Node.h"
#include "../composite_pattern/Negate_Node.h"

class Visitor
{
    public:
        virtual ~Visitor (void) {};
        virtual void visit( Addition_Node & node ) = 0;
        virtual void visit( Number_Node & node ) = 0;
        virtual void visit( Subtraction_Node & node ) = 0;
        virtual void visit( Multiplication_Node & node ) = 0;
        virtual void visit( Division_Node & node ) = 0;
        virtual void visit( Modulus_Node & node ) = 0;
        virtual void visit( Negate_Node & node ) = 0;
};

#endif
