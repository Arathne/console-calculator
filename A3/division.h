#ifndef DIVISION_COMMAND_H
#define DIVISION_COMMAND_H

#include "binary.h"

class Division : public Binary
{
    public:
        void execute (void);
        int evaluate (int number1, int number2) const;
};

#endif
