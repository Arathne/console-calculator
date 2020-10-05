#ifndef MODULUS_H
#define MODULUS_H

#include "Binary.h"
#include <stdexcept>

class Modulus : public Binary
{
    public:
        Modulus (void);
        ~Modulus (void);
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
