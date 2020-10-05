#ifndef UNARY_H
#define UNARY_H

#include "Operator.h"

class Unary : public Operator
{
    public:
        virtual ~Unary (void) {};
        virtual int calculate (int number) = 0;
};

#endif
