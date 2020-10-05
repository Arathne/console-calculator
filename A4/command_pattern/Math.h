#ifndef MATH_H
#define MATH_H

#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Modulus.h"
#include "Negation.h"

class Math
{
    public:
        Math (void);
        ~Math (void);

        int add (int num, int num2);
        int subtract (int num, int num2);
        int multiply (int num, int num2);
        int divide (int num, int num2);
        int modulus (int num, int num2);
        int negate (int num);


   private:
        Addition add_;
        Subtraction subtract_;
        Multiplication multiply_;
        Division divide_;
        Modulus modulus_;
        Negation negate_;
};

#endif
