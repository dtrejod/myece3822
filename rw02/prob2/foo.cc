#include "foo.h"
#include <string.h>

int main (int argc, char** argv) {

    // declare some variables
    //
    // Create a car object called tcar
    //
    Car tcar;

    // make an array of car objects pointers. 
    //
    Car** cars = new Car*[10];

    // Create a 100 byte array string pointer.
    //
    char* tstr = new char[100];

    // call the function
    // Copy the command line passed character array (argv[1]) to our 100 byte
    // string pointer we created previously.
    //
    strcpy(tstr, argv[1]);

    // Inside the car class we now call the function fun.
    //
    tcar.fun(cars, (char*)tstr);

    // We cleanup the 100 byte string chacter we created earlier.
    //
    delete tstr;

    // display debug information
    //
    cars[1]->debug();
}

