#include "sample/Formula.h"

int Formula::bla(int arg1)
{
        return arg1 * 2;
}

unsigned int Factorial(unsigned int number)
{
        return number <= 1 ? number : Factorial(number - 1) * number;
}