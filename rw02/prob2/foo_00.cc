# include "foo.h"
# include <string.h>

// Class car functions
//

// Class car constructor
//
Car::Car(float speed_a) {
    // Intantiate the variables that make up the car class
    //
    speed = speed_a;
    model = (char*)NULL;
    brand = (char*)NULL;
}
// Class car destructor
//
Car::~Car() {
    // We clean up the character arrays in the class car. If we we didn't 
    // delete the data in the character array only the pointer would be 
    // deleted upon deleting a car class object. Potential memory leak.
    //
    delete [] model;
    delete [] brand;
}

// Class car set model function 
//
bool Car::set_model(char* model_a) {
    // Set the variable model contained in car equal to the passed parameter
    //
    model = model_a;
    return true;
}

// Class car debug function.
//
bool Car::debug() {
    // print out hello world along side the model variable that is referenced
    // by this car object.
    //
    printf("hello world: %s\n", model);
    return true;
}

// implement a function
//
bool Car::fun(Car** car_a, char* str) {
    
    // Create a car object inside the car_a array.
    //
    car_a[1] = new Car;
    
    // Copy the str pointer to a new sting pointer so it does not get deleted
    // (from within the main function)
    // First find the number of bytes in str
    //
    int strL = strlen(str);
    
    // Re-allocate memory so it holds our string
    //
    model = new char[strL + 1];
    
    // Copy string input arugement into model memory location
    //
    memcpy(model, str, strL);

    // The arrow operand is equvilent to (*car_a[0]).set_model(str)
    //
    car_a[1]->set_model(model);

    return true;
}
