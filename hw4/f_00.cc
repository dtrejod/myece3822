
// Main program to complete hw4 Software Tools

// Import Libraries
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

float ece_3822_add_sin(float x, float y);

int main(void){
    // Declare Working Variables
    float out, x, y;
    // First we print Hello Worl
    printf("Hello World\n");
    
    // Prompt user to input variables
    printf("x =: ");
    scanf("%f",&x);
    printf("y = : ");
    scanf("%f",&y);

    out = ece_3822_add_sin(x,y);
    printf("sin(%f) + sin(%f) = %f\n", x, y, out);
}
