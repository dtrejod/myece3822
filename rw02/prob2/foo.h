#include <stdio.h>
#include <stdlib.h>

// Class car object definition
//
class Car {

    // protected 
    // Protect variables for the class car object. These variables will only
    // be seen by the functions inside the car object and any class that
    // instaitates the car class.
    //
    protected:
        float speed;
        char* model;
        char* brand;

    // public
    // Items under public are visible outside the car class object.
    //
    public:
        // Constructor. Use a default speed of 60 if the speed is not specified
        // when the car object is created
        //
        Car(float arg = 60.0);

        // Destructor. Run this funtion when the car object id deleted.
        //
        ~Car();
        
        // Car object funtions.
        //

        // Set model changes the model variable of this car object
        //
        bool set_model(char* model_a);
        
        // Creates a copy of car objects with the same model as the first car
        // object
        //
        bool fun(Car** car, char* str);

        // Debug print the the variables that make up this car object.
        //
        bool debug();

};
