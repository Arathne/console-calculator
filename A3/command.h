#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <Stack.h>

public Command
{
    public:
        virtual void execute (void) = 0;
        virtual int evaluate (int number1, int number2) const = 0;
        virtual ~Command (void) {};

    protected:
        Stack <int> & stack_;
};

#endif
