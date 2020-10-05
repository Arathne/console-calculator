#ifndef OPERATOR_H
#define OPERATOR_H

#include "Command.h"

class Operator : public Command
{
    public:
        virtual ~Operator (void) {};
        virtual int precedence (Operator & op) const = 0;
        virtual int level (void) const = 0;
};

#endif
