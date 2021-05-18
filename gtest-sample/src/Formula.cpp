#include "Formula.h"

int Formula::bla(int arg1)
{
        return arg1 * 2;
}

unsigned int Factorial(unsigned int number)
{
        return number <= 1 ? 1 : Factorial(number - 1) * number;
}