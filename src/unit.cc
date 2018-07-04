#include <math.h>
#include "unit.h"

double newton_sqrt(double n)
{
    double x = 1.0;
    while(fabs(x * x - n) > EPSLON)
    {
        x = x - (x * x - n) / (2 * x);
    }
    return x;
}