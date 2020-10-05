#ifndef ADDITION_COMMAND_H
#define ADDITION_COMMAND_H

#include "binary.h"

class Addition : public Binary
{
    public:
        Addition (void);
        Addition (Stack <int> & stack);
        ~Addition (void);
        void execute (void);
        int evaluate (int number1, int number2) const;
};

#endif
