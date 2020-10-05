#ifndef DIVISION_H
#define DIVISION_H

#include <stdexcept>
#include "Binary.h"

class Division : public Binary
{
    public:
        Division (void);
        ~Division (void);
        int calculate (int num1, int num2);
        int precedence (Operator & op) const;
        int level (void) const;
        int state (void) const;
        void execute (Stack<int> & stack);
        std::string get_string (void) const;

   private:
        int level_;
        int state_;
};

#endif
