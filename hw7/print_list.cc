# include <stdio.h>
# include <getopt.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <cctype>
/*
 * C++ Program
 * ECE 3822 Homework Assigment Number 7
 * Create a program that reads in file names and sorts alphabetically
 * 
 * Author: Devin Trejo
 *
*/

// -------------------
// - FN Declerations -
// -------------------
bool charCompare(char*, char*);
void print_usage(void);
char* charToLower(char* charA);

// --------------------
// - STATIC CONSTANTS -
// --------------------

// CHAR_LEN is the length of our read in buffer
//
static const int CHAR_LEN = 255;

// NUM_NAMES is the max number of names our program can possible hold. 
//
static const int NUM_NAMES = 1000;

// -----------
// - CLASSES -
// -----------

// NL is a linked list that stores a list of nameNodes
//
class NL{
    public:
        // Constructor
        //
        NL(bool debug_a = false);

        // Destructor
        // 
        ~NL(void);

        // Class Function Definitions
        //

        // Read in File
        //
        void read(FILE*);
        //void write(void);
        void print(void);
        void sort(void);
        void debug(void);
        int getLength(void);
    private:
        // Internal class functions
        //
        void debug(char*);

        // Store a list of names
        //
        char* names[NUM_NAMES];
        
        // Stores the length of the linked list
        //
        int length;
        bool debugV;
};

NL::NL(bool debug_a){
    if (debug_a){
        debug();
        char* const funName =  new char[CHAR_LEN];
        strcpy(funName, "NL::NL");
        debug(funName);
        delete [] funName;
    }
    else debugV = debug_a;
    // Intialize each element in names as NULL
    //
    for (int i = 0; i < NUM_NAMES; i++){
        names[i] = (char*)NULL;
    }

    // Constructor
    //
    length = 0;
}

NL::~NL(void){
    // Run debug if true
    //
    if (debugV){
        char* const funName =  new char[CHAR_LEN];
        strcpy(funName, "NL::~NL");
        debug(funName);
        delete [] funName;
    }
    // Destructor
    //
    // For each element in our array delete the pointer
    //
    for (int i = 0; i < NUM_NAMES; i++){
        delete names[i];
    }
}

int NL::getLength(void){
    // Run debug if true
    //
    if (debugV){
        char* const funName =  new char[CHAR_LEN];
        strcpy(funName, "NL::getLength");
        debug(funName);
        delete [] funName;
    }
    // Return legnth 
    //
    return length;
}

// Input Name into class data
//
void NL::read(FILE* fp){
    // Run debug if true
    //
    if (debugV){
        char* const funName = new char[CHAR_LEN];
        strcpy(funName, "NL::read");
        debug(funName);
        delete [] funName;
    }
   
    // Check if file is valid
    //
    if (fp == NULL){
        // File does not exist. Skip and go to next file
        //
        printf("Error. File does not exsit.\n");
        exit(EXIT_FAILURE);
    }

    // Char String Buffer
    //
    char* buffer = new char[CHAR_LEN + 1];

    // Size of string containing first name
    //
    int strSize;

    while((fgets(buffer, CHAR_LEN, fp) != NULL)){
        // Create a new character array with proper size for name
        //
        strSize = strlen(buffer);
        
        // Allocate memory to name list of perfect size
        //
        char* nodeName = new char[strSize + 1];
        
        // Copy the string to our perfectly memory allocated array
        //
        strcpy(nodeName, buffer);
        names[length] = nodeName;
        length++;
    }
}

void NL::print(void){
    // Run debug if true
    //
    if (debugV){
        char* const funName =  new char[CHAR_LEN];
        strcpy(funName, "NL::print");
        debug(funName);
        delete [] funName;
    }
    // Keep a line number tracker long
    //
    long line_num = 0;

    for (int i = 0; i < length; i++){
        fprintf(stdout, "%08d: %s", line_num, names[i]);
        line_num++;
    }
}

// Use bubble sort to sort this nameList (NL)
//
void NL::sort(void){    
    // Run debug if true
    //
    if (debugV){
        char* const funName =  new char[CHAR_LEN];
        strcpy(funName, "NL::sort");
        debug(funName);
        delete [] funName;
    }
    // Declare a variable to hold if we swapped or not
    //
    bool swapped;
    
    // Create a temp char pointer
    //
    char* temp = (char*)NULL;

    // Loop over all elements
    //
    for (int i = 0; i < length; i++){
        // Each iterative loop we reset swapped
        //
        swapped = false;
        // second loop to go from bottom up 
        //
        for (int j = length - 1; j > 0; j--){
            // For each word compare it to the next word in the array
            // and determine which should come first
            //
            if (charCompare(names[j], names[j-1])){
                // Swap the char pointers in the names array
                //
                temp = names[j];
                names[j] = names[j-1];
                names[j-1] = temp;

                // We performed a swap so set variable equal to true
                //
                swapped = true;
            }
        }
    if (swapped = false) break; 
    }   
}

// Print debuging info
// 
void NL::debug(char* delim){
    fprintf(stdout, "DEBUG:FUNCTION CALL: %s\n", delim);
}

// Enable debuging
//
void NL::debug(void){
    debugV = true;
    char* const funName = new char[CHAR_LEN];
    strcpy(funName, "NL::debug");
    debug(funName);
    delete [] funName;
}

// ---------------
// - DATA STRUCT -
// ---------------


// Input Arugment Structure for holding our possible input parameters
//
static struct option long_options[] = {
        // These options set a flag
        //
        {"debug", no_argument, 0 ,'d'},
        {"sort",  no_argument, 0, 's'},
        {"help",  no_argument, 0, 'h'},
        {"length", no_argument,0, 'l'},
        {0,       0,           0, 0}
};   

//  Print program  proper usage function
//

// ------------------
// - PRGM FUNCTIONS -
// ------------------

// Print usage prints how to use the program
//
void print_usage(void){
    printf("Usage: foo.exe [options] file \n"
                "Options:\n"
                "   --help, -h          Print help file\n"
                "   --debug, -d         Debug program\n"
                "   --sort, -s          Sort input file alphabetically\n"
                "   --length, -l        Print the number of names in the "
                                        "file\n");
}

// Compares to char arrays (aka strings) and determines which comes first
// alpabetically. Returns 1 if name_b comes before name_a and false otherwise
//
bool charCompare(char* name_a, char* name_b){
    // First find the legnth of each name
    //
    int aL, bL, xL;
    aL = strlen(name_a);
    bL = strlen(name_b);
    
    // Get the longest string length
    //
    if (aL < bL) xL = bL;
    else xL = aL;
 
    // Create a copy of each string
    //
    char* nameA = (char*)NULL;
    char* nameB = (char*)NULL;

    // Convert both names to lowercase
    //
    nameA = charToLower(name_a);
    nameB = charToLower(name_b);

    // Loop over each letter in each name
    //
    for(int i = 0; i <= xL; i++){
        // Check see if a character in nameA comes after nameB
        //
        if(nameA[i] < nameB[i]){
            // Memory cleanup
            //
            delete [] nameA;
            delete [] nameB;
            return true;
        }
        else if (nameA[i] > nameB[i]){
            // Memory cleanup
            //
            delete [] nameA;
            delete [] nameB;
            return false;
        }
    }

    // Memory cleanup
    //
    delete [] nameA;
    delete [] nameB;
    return false;
}

// Compares to char arrays (aka strings) and determines which comes first
// alpabetically. Returns 1 is name_b comes before name_a and false otherwise
// Source: "http://stackoverflow.com/questions/27054353/" ...
//      "c-converting-array-of-char-into-lower-case"
//
char* charToLower(char* charA){
    // Create a new char pointer so we don't compromise the passed pointer
    //
    char* newCharA = new char[strlen(charA)];
    
    // Get legnth of char array
    //
    int aL = strlen(charA);

    // Loop over each letter in array and convert to lower
    //
    for(int i = 0; i <=aL; i++){
        newCharA[i] = tolower(charA[i]);
    }
    return newCharA;
}

// --------
// - MAIN -
// --------

// Main program reads, sorts (if desired), and prints loaded in from first
// input argument
//
int main (int argc, char *argv[]){
    int opt = 0;
    int opterr = 0;
    bool debugF = false;
    bool sortF = false;
    bool lenF = false;

    // Parse input arugments
    //
    while ((opt = getopt_long(argc, argv, "dshl", long_options, 
                &opterr)) != -1){
        switch(opt){
            case 'd':
                debugF = true;
                break;
            case 's':
                sortF = true;
                break;
            case 'l':
                lenF = true;
                break;
            case 'h':
                print_usage();
                exit(EXIT_SUCCESS);
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }
    
    FILE* fp;
    for (int i = optind; i < argc; i++){
        // Display which file we are currently processing
        //
        fprintf(stdout, "Processing file: %s\n", argv[i]);
        
        // Open file
        //
        fp = fopen(argv[i], "r");

        NL nameList(debugF);
        nameList.read(fp);
        // Sort NameList if flag is set
        //
        if (sortF) {
            nameList.sort();
        }
        if (lenF){
           fprintf(stdout, "Number of names in file = %d\n", 
                   nameList.getLength());
        }   
        // Print Name List Nicely
        //
        nameList.print();
    }
    // Exit Gracefully
    //
    fprintf(stdout, "Program finished succesfully\n");
}
