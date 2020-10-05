#ifndef EXPRESSION_BUILDER_H
#define EXPRESSION_BUILDER_H

#include <stdexcept>

#include "../composite_pattern/Number_Node.h"
#include "../composite_pattern/Addition_Node.h"
#include "../composite_pattern/Subtraction_Node.h"
#include "../composite_pattern/Multiplication_Node.h"
#include "../composite_pattern/Division_Node.h"
#include "../composite_pattern/Modulus_Node.h"
#include "../composite_pattern/Negate_Node.h"

class Expression_Builder
{
    public:
        virtual ~Expression_Builder (void) {};
        
        virtual void build_number (int number) = 0;
        virtual void build_add (void) = 0;
        virtual void build_subtract (void) = 0;
        virtual void build_multiply (void) = 0;
        virtual void build_divide (void) = 0;
        virtual void build_modulus (void) = 0;
        virtual void build_negate (void) = 0;
};

#endif
