#ifndef COMMAND_H
#define COMMAND_H

#include "../data_structures/Stack.h"

class Command
{
    public:
        virtual ~Command (void) {};
        virtual int state (void) const = 0;
        virtual void execute (Stack<int> & stack) = 0;
};

#endif
