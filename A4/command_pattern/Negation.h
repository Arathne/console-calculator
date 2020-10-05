#ifndef NEGATION_H
#define NEGATION_H

#include "Unary.h"

class Negation : public Unary
{
    public:
        Negation (void);
        ~Negation (void);
        int precedence (Operator & op) const;
        int level (void) const;
        int calculate (int number);
        int state (void) const;
        void execute (Stack<int> & stack);
        std::string get_string (void) const;

    private:
        int level_;
        int state_;
        Stack<int> stack_;
};

#endif
