# include <stdio.h>
# include <getopt.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <cstring>

/*
 * C++ Program
 * ECE 3822 Exam2
 * Author: Devin Trejo
 *
*/

static const int CHAR_LEN = 255;

// Classes
//

enum STATE { OFF = 0, ON = 1 };

// Lamp stores a persons name and a pointer to the next Lamp
//
class Lamp{
    public:
        // Constructor
        //
        Lamp(int length_a = -1, int height_a = -1, int width_a = -1, 
            int watts = -1, char* brand_a = (char*)NULL);       
        // Destructor
        ~Lamp();

        // Class Functions
        //
        bool set_brand(char*);
        bool debug(FILE*);
        Lamp(int);
    private:
        char name[CHAR_LEN];
        Lamp* next;
    protected:
        int length;
        int height;
        int width;
        int watts;
        char* brand;
        STATE state;
};

Lamp::Lamp(int length_a, int height_a, int width_a, 
            int watts, char* brand_a){
    // Constructor
    //
    length = length_a;
    height = height_a;
    width = width_a;
    watts = watts;
    brand = new char[CHAR_LEN];
    strcpy(brand, brand_a);
}
Lamp::~Lamp(void){
    // Destructor
    //
    delete [] brand;
}
bool Lamp::set_brand(char* arg){
    strcpy(brand, arg);
}

// Print lamp data
//
bool Lamp::debug(FILE* arg){
    fprintf(arg, "length = %d\n", length);
    fprintf(arg, "height = %d\n", height);
    fprintf(arg, "width = %d\n", width);
    fprintf(arg, "watts = %d\n", watts);
    fprintf(arg, "brand = %s\n", brand);
    fprintf(arg, "state = %d\n", state);
    fprintf(arg, "Length = %d\n\n", state);
}

int main (int argc, char *argv[]){
    FILE* fp;

    fp = stdout; 
    fprintf(fp, "%s", argv[1]);
    Lamp myLamps [7];
    
    for(int i = 1; i <=argc; i++){
       myLamps[i].set_brand(argv[i]);
        
    }
    
    // Print Output
    //
    for(int i = 1; i <=argc; i++){
       myLamps[i].debug(fp);
    }
    
    // Exit Gracefully
    //
}
