#include "Math.h"


Math::Math (void) {}

Math::~Math (void) {}

int Math::add (int num, int num2) 
{
    return add_.calculate( num, num2 ); 
}

int Math::subtract (int num, int num2)
{
    return subtract_.calculate( num, num2 ); 
}

int Math::multiply (int num, int num2)
{
    return multiply_.calculate( num, num2 ); 
}

int Math::divide (int num, int num2)
{
    return divide_.calculate( num, num2 ); 
}

int Math::modulus (int num, int num2)
{
    return modulus_.calculate( num, num2 ); 
}

int Math::negate (int num)
{
    return negate_.calculate( num ); 
}
