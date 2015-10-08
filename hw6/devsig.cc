# include <stdio.h>
# include <unistd.h>
# include "devsig.h"

// Functions
//

// Buffer size in bytes
static const int buffer_size=1024;

int parse_signal_file(int data_inter, int show_line, FILE* fp){
    
    // Line number tracker
    //
    long line_num = 0;
     
    // Create a buffer of size buffer_size in bits
    //
    
    if (data_inter == 0){
        short int buffer[buffer_size];
        // Read in data in buffer_size chunks until end of file
        //
        while (fread(buffer, sizeof(short int), 
                        buffer_size, fp) != 0){
            // We parse buffer into data_size bits
            //
            for(int i = 0; i <= sizeof(buffer) / sizeof(short int); i++){
                // If showline number is true then display line number
               //fprintf(stdout, "i = %d ", i); 
                if (show_line == 1){
                    fprintf(stdout, "%08d:    ", line_num);
                    line_num += 1;
                }
                fprintf(stdout, "%hd\n", buffer[i]);
            }
        }
    }
    else{
        float buffer[buffer_size];
        // Read in data in buffer_size chunks until end of file
        //
        while (fread(buffer, sizeof(float),
                        buffer_size, fp) != 0){
            // We parse buffer into data_size bits
            // //
            for(int i = 0; i <= sizeof(buffer) / sizeof(float); i++){
               // If showline number is true then display line number
               //fprintf(stdout, "i = %d ", i); 
                if (show_line == 1){
                    fprintf(stdout, "%08d:    ", line_num);
                    line_num += 1;
                }
                fprintf(stdout, "%g\n", buffer[i]);
            }
        }
    }
    return 0;
}
