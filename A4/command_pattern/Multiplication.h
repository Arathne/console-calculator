#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Binary.h"

class Multiplication : public Binary
{
    public:
        Multiplication (void);
        ~Multiplication (void);
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
