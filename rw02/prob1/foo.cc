# include <stdio.h>
//# include <stdlib.h>
# include <string.h>
# include "lamp.h"
/*
 * C++ Program
 * ECE 3822 Exam2
 * Author: Devin Trejo
 *
*/
int main (int argc, char *argv[]){
    // Create an array of lamp objects depending on how many input arugments
    // we see. Note we minus one becaues argv[0] is the name of the function. 
    //
    Lamp myLamps[argc - 1];
    
    // Define variable to hold size of string that is in lampName command line
    // input
    //
    int lampSize; 

    // Loop through all the command line input lamp names
    //
    for(int i = 0; i < argc - 1; i++){
        // take arugment input and store in temp variable
        //
        char* temp = argv[i+1];
        
        // allocate space for lampName using string stored in temp variable.
        // We add one to the size for the end of string character '\0'
        //
        lampSize = strlen(temp);
        char* lampName = new char[lampSize + 1];

        // Copy the temp variable holding to lampName variable
        //
        strcpy(lampName, temp);

        // Set the name of the lamp
        //
        myLamps[i].set_brand(lampName);
    }
    // Once out of the for loop the temp and lampName variables are cleared.
    // freeing up memory allocation

    // Print contents of myLamps usign debug function
    //
    for(int i = 0; i < argc - 1; i++){
       myLamps[i].debug(stdout);
    }
    
    // Exit Gracefully
    //
    return 0;
}
