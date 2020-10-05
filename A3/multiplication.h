#ifndef MULTIPLICATION_COMMAND_H
#define MULTIPLICATION_COMMAND_H

#include "binary.h"

class Multiplication : public Binary
{
    public:
        void execute (void);
        int evaluate (int number1, int number2) const;
};

#endif
