#ifndef BINARY_H
#define BINARY_H

#include "Operator.h"
#include <string>

class Binary : public Operator
{
    public:
        virtual ~Binary (void) {};
        virtual int calculate (int num1, int num2) = 0;
        virtual int precedence (Operator & op) const = 0;
        virtual std::string get_string (void) const = 0;
};

#endif
