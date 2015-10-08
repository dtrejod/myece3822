# include <stdio.h>
# include <getopt.h>
# include <stdlib.h>
# include <unistd.h>
# include "devsig.h"

/*
// C++ Progam
// ECE 3822 Homework Assigment Number 6
// "The goal of this homework is simple. Create a 'print_signals" program
//     in Unix by writing a C program"
// Author: Devin Trejo
//
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

 
//  Print program  proper usage function
//
void print_usage(){
    printf("Usage: print_signals [options] file \n"
                "Options:\n"
                "   -h, --help          Print help file\n"
                "   --numbers, --no, -n Display line numbers on output\n"
                "   -f, --float         Interpret data as 4-byte floating "
                                        "point numbers\n"
                "   -i, --integer       Interpret data as 16-bit integers\n"
                "Default Paramters:\n"
                "   - [ ] Display line numbers\n"
                "   - [✓] Interpret data as 16 bit intergers\n"
                "   - [ ] Interpret data as 4 byte floats\n");
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
        printf("    - [✓] Display line numbers\n");
    }
    else{
        printf("    - [ ] Display line numbers\n");
    }
    if (data_inter){
        printf("    - [ ] Interpret data as 16 bit intergers\n");
        printf("    - [✓] Interpret data as 4 byte floats\n");
    }
    else{
        printf("    - [✓] Interpret data as 16 bit intergers\n");
        printf("    - [ ] Interpret data as 4 byte floats\n");
    }

    printf("\n");
    FILE* fp;
    
    // Check for piped input
    //
    if (isatty(fileno(stdin)) == 0) {
    // Display which file we are currently processing
    //
    fp = stdin;

    printf("\nProcessing from stdin:\n");
    // Call function to interpret data
    //
    parse_signal_file(data_inter, show_line, fp);

    }
    // Parse each input file
    //
    for (i = optind; i < argc; i++){
        // Display which file we are currently processing
        //
        printf("\nProcessing file: %s\n", argv[i]);
        
        // Open file
        //
        FILE* fp;
        fp = fopen(argv[i], "rb");

        // Check if file exists
        //
        if (fp == NULL){
            // File does not exsists. Skip and go to next file
            //
            printf("Error. File '%s' does not exsit\n", argv[i]);    
            continue;
        }
        // Call function to interpret data
        //
        parse_signal_file(data_inter, show_line, fp);
    }
    return 0;
}
