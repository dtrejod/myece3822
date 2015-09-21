// Create a function called ece_3822_add_sin that takes two floating-point
//  values as arguments and returns the sum of the sin of each value (using the
//  sin function in math.h). Save it to a file called f_01.cc.

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

float ece_3822_add_sin(float x, float y){
    // Working Variables
    float out, xsin, ysin;

    // Take the sin of both numbers
    xsin = sinf(x);
    ysin = sinf(y);
    out = xsin + ysin;
    return out;
}

