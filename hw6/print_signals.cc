# include <stdio.h>
# include <string.h>
# include <getopt.h>
# include <stdlib.h>

/*
// C++ Progam
// ECE 3822 Homework Assigment Number 6
// "The goal of this homework is simple. Create a 'print_signals" program
//     in Unix by writing a C program"
// Author: Devin Trejo
//
*/

// Function Declaration
//
//int parse_signal_file(int data_type, int show_line, FILE* fp);


// Functiions
//

static const int buffer_size=1024;

int parse_signal_file(int data_inter, int show_line, FILE* fp){
    
    // Line number tracker
    //
    long line_num = 0;
     
    char buffer[buffer_size*8];
    // Read in data in buffer_size chunks until end of file
    //
    while ((fread(buffer, buffer_size, 1, fp) == 1)){
        // fprintf(stdout, "Debug RAW: %s\n", buffer);
        //

        // Parse the buffer into data-size bytes
        //

        // We parse buffer as a 16 bit integer (or 2 bytes
        if(data_inter == 0){
            int sub_buffer;
            for(int i = 0; i <= buffer_size, i = i+2){
                sub_buffer = atoi(buffer
                if (show_line == 1){
                    fprintf(stdout, "%08d: %d\n", line_num,atoi(buffer));
                    line_num+=1; 
                }
                else{
                    fprintf(stdout, "%d\n", atoi(buffer));
               }    
            
            }
        
        }

        // Print data
         
        else{
            if(data_inter == 0){

            }
            else{
                fprintf(stdout, "%f\n", atof(buffer));
            }
        }
    }   
    return 0;
}

/*
int parse_signal_file(float buffer, int show_line, FILE* fp){
    
    // Line number tracker
    //
    long line_num = 0;
     
    // Parse file until end of file
    //
    while ((fread(buffer, buffer_size, 1, fp) == 1)){
        if (show_line == 1){
            fprintf(stdout, "%d: %f\n", line_num, buffer);
            line_num += 1;
        }   
        else{
            fprintf(stdout, "%f\n", buffer);
        }
    }
    return 0;
}
*/

// Input Arugment Structure
//
static struct option long_options[] = {
        // These options set a flag
        //
        {"numbers", no_argument, 0 ,'n'},
        {"no",      no_argument, 0, 'n'},
        {"help",    no_argument, 0, 'h'},
        {"float",   no_argument, 0, 'f'},
        {"integer", no_argument, 0, 'i'},
        {0,         0,           0, 0}
};   

 
// Invalid usage. Print proper usage
//
void print_usage(){
    printf("Usage: print_signals [options] file \n"
                "Options:\n"
                "   -h, --help          Print help file\n"
                "   --numbers, --no, -n Display line numbers on output\n"
                "   -f, --float         Interpret data as 4-byte floating "
                                        "point numbers\n"
                "   -i, --integer       Interpret data as 16-bit integers\n"
                "Default:\n"
                "   - No line numbers are displayed\n"
                "   - Default data is inputed at 16-bit integers\n");
}

int main (int argc, char *argv[]){
    // Default Values:
    //      0 = false
    //      1 = true
    //      data_inter:
    //          0: integers
    //          1: float
    int opt = 0;
    int opterr = 0;
    int show_line = 0,
        data_inter = 0;
    int i;

    // Parse input arugments
    //
    while ((opt = getopt_long(argc, argv, "nfih", long_options, 
                &opterr)) != -1){
        switch(opt){
            case 'n':
                show_line = 1;
                //printf("show_line = %d\n", show_line);
                break;
            case 'f':
                data_inter = 1;
                //printf("data_inter = %d\n", data_inter);
                break;
            case 'i':
                data_inter = 0;
                //printf("data_inter = %d\n", data_inter);
                break;
            case 'h':
                print_usage();
                exit(EXIT_SUCCESS);
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }
    // Display parameters
    //
    printf("Display Paramters:\n");
    if (show_line){
        printf("    Displaying line numbers\n");
    }
    else{
        printf("    Not displaying line numbers\n");
    }
    if (data_inter){
        printf("    Interpreting data as 4 byte floats\n");
    }
    else{
        printf("    Interpreting data as 16 bit intergers\n");
    }

    printf("\n\n");
    for (i = optind; i < argc; i++){
        // Display which file we are currently processing
        //
        printf("Processing file: %s\n", argv[i]);
        
        // Open file
        //
        FILE* fp;
        fp = fopen(argv[i], "r");

        // Check if file exists
        //
        if (fp == NULL){
            // File does not exsists. Skip and go to next file
            //
            printf("Error. File '%s' does not exsit\n", argv[i]);    
            continue;
        }
        parse_signal_file(data_inter, show_line, fp);
    }
}

   