# include <stdio.h>

// Classes
//
enum STATE { OFF = 0, ON = 1 };

// Lamp stores a the definition for a lamp 
//
class Lamp{
    public:
        // Constructor. We set our default values here (-1)
        //
        Lamp(int length_a = -1, int height_a = -1, int width_a = -1,
            int watts = -1, char* brand_a = (char*)NULL);       
        
        // Destructor
        ~Lamp();

        // Class Functions
        //
        bool set_brand(char*);
        bool debug(FILE*);
    protected:
        // Define parameters that make up a lamp
        //
        const static int ac_power = 60;
        int length;
        int height;
        int width;
        int watts;
        char* brand;
        STATE state;
};

