#include <stdio.h>
#include <math.h>
int main(void)
{
    double result;
    double x = 3.0;
    double y = 4.0;
    result = hypot(x, y);
    printf("The hypotenuse is: %lf\n", result);
    return 0;
}