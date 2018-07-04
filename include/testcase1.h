#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include "mytest.h"
#include "unit.h"

TEST(unit, newton_sqrt)
{
    for(int i = 0; i <= 100; i++)
    {
        double x = newton_sqrt(i);
        EXPECT_EQ(EPSLON, fabs(x * x - i));
        printf("error %lf * % lf != %d\n", x, x, i);
    }
}
#endif
