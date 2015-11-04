# include "lamp.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

Lamp::Lamp(int length_a, int height_a, int width_a, 
        int watts_a, char* brand_a){
    // Constructor. Use passed inputs or default values. 
    //
    length = length_a;
    height = height_a;
    width = width_a;
    watts = watts_a;
    brand = brand_a;
    state = OFF;
}

Lamp::~Lamp(void){
    // Destructor
    //
    
    // We only care about deleting memory allocated to brand character array
    // since it is a pointer and only the reference to the pointer is deleted
    // when the class goes out of scope
    //
    delete [] brand;
}

bool Lamp::set_brand(char* arg){
    // Set brand equal to pass varaible pointer arg. 
    //
    brand = arg;
    return true;
}

// Print lamp data
//
bool Lamp::debug(FILE* fp){
    fprintf(fp, "brand = %s\n", brand);
    fprintf(fp, "length = %d\n", length);
    fprintf(fp, "height = %d\n", height);
    fprintf(fp, "width = %d\n", width);
    fprintf(fp, "watts = %d\n", watts);
    fprintf(fp, "ac_power = %d\n", ac_power);
    fprintf(fp, "state = %d\n\n", STATE());
    return true;
}
