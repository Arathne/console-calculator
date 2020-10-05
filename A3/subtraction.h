#ifndef SUBTRACTION_COMMAND_H
#define SUBTRACTION_COMMAND_H

#include "binary.h"

class Subtraction : public Binary
{
    public:
        void execute (void);
        int evaluate (int number1, int number2) const;
};

#endif
