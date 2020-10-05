#ifndef NUMBER_H
#define NUMBER_H

#include "Command.h"

class Number : Command
{
    public:
        Number (void);
        Number (int number);
        ~Number (void);
        void execute (Stack<int> & stack);
        int state (void) const;
        
    private:
        int state_;
};

#endif
