# include <stdio.h>
# include <getopt.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
 * C++ Program
 * ECE 3822 Homework Assigment Number 7
 * Create a program that reads in file names and sorts alphabetically
 * 
 * Author: Devin Trejo
 *
*/

static const int CHAR_LEN = 255;

// Classes
//
// NL is a linked list that stores a list of nameNodes
//
class NL{
    public:
        // Constructor
        //
        NL();

        // Destructor
        // 
        ~NL();

        // Class Function Definitions
        //

        // Read in File
        //
        void read(FILE*);
        void write(void);
        void print(void);
        int getLength(void);
    private:
        // Store data in private
        //

        // Store a list of names
        //

        // last points to the last nameNode in the linked list
        //
        nameNode* last;
        
        // Stores the legnth of the linked list
        //
        int length;
        
        void swapNodes(nameNode* current);
   protected:
    
};

NL::NL(void){
    // Constructor
    //
    length = 0;
}

NL::~NL(void){
    // Destructor
    //

}

void NL::swapNodes(nameNode* current){
    // Setup temporary nameNode holder variable
    //
    nameNode* temp;
    nameNode* temp2;

    // Set the current nodes next node to the temp nextNode
    //
    temp = current.getNext();
    temp2 = temp.getNext();

    // Reorganize the order of the linked list
    //
    temp.setNext(current);
    current.setNext(temp2);
}

int NL::getLength(void){
    return length;
}

// Input Name into class data
//
void NL::read(FILE* fp){
    
    // Char String Buffer
    //
    char buffer[CHAR_LEN];

    // Index Tracker
    //
    int i = 0;
    
    // Current Character Tracker
    //
    int c; 
    
    // Size of string containing first name
    //
    int strSize;

    // Create a nameNode to store name
    //
    nameNode node;

    // Set the head of the nameList (NL) equal to the firs nameNode
    //
    head = &node;

    while((c=fgetc(fp) != EOF)){
        if (c=='\n'){
            // Create a new character array with proper size for name
            //
            strSize = strlen(buffer);
            char* nodeName = new char[strSize + 1];
            strcpy(nodeName, buffer);

            // Store Name in class
            //
            node.setName(nodeName);
            
            // Create the new nameNode and point the previous to the next
            //
            nameNode nodeNew*;
            node.setNext(nodeNew);
            node = nodeNew;

            // Reset read in temp variables
            buffer = (char)NULL;
            i = 0;
        }
        else{
            buffer[i] = c;
            i++;
        }
    }
}

void NL::print(void){
    // Keep track of current nameName
    //
    nameNode* currentNode;
    
    // Set current node equal to the headnode
    //
    currentNode = head;
    do{
        fprintf(stdout, "%s\n", currentNode.getName());
        currentNode = currentNode.getNext();
    } (currentNode != last)
}

void NL::sort(void){
   // Use bubble sort to sort this nameList (NL)
   //
   nameNode* currentNode = head;
   bool swapped;
   index = 0;
   while(1){
        swapped = false;
        for (int i = 0; i <= legnth; i++){
            if(currentNode.getNext().getName()[0] - currentNode.getName()[0]){
                swapNodes(currentNode)
                swapped = true;
            }
            currentNode = currentNode.getNext();
        }
        if (swapped = false){
            break;
        }
}

// Input Arugment Structure
//
static struct option long_options[] = {
        // These options set a flag
        //
        {"debug", no_argument, 0 ,'d'},
        {"sort",  no_argument, 0, 's'},
        {"help",  no_argument, 0, 'h'},
        {0,       0,           0, 0}
};   

//  Print program  proper usage function
//
void print_usage(){
    printf("Usage: print_signals [options] file \n"
                "Options:\n"
                "   --help, -h          Print help file\n"
                "   --debug, -d         Debug program\n"
                "   --sort, -s          Sort input file alphabetically "
}


int main (int argc, char *argv[]){
    int opt = 0;
    int opterr = 0;
    bool debugF = false;
    bool sortF = flase;

    // Parse input arugments
    //
    while ((opt = getopt_long(argc, argv, "nfih", long_options, 
                &opterr)) != -1){
        switch(opt){
            case 'd':
                debugF = true;
                break;
            case 's':
                sortF = true;
                break;
            case 'h':
                print_usage();
                exit(EXIT_SUCCESS);
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
    }
    
    print('\n');

    FILE* fp;
    // Display which file we are currently processing
    //
    printf("\nProcessing file: %s\n", argv[i]);
    
    // Open file
    //
    fp = fopen(argv[i], "r");

    if (fp == NULL){
        // File does not exist. Skip and go to next file
        //
        printf("Error. File '%s' does not exsit.\n", argv[i]);
        exit(EXIT_FAILURE);
    }
    NL nameList;
    nameList.read(fp);
    
    // Sort NameList if flag is set
    //
    if (sortF) nameList.sort();
    
    // Print Name List Nicely
    //
    nameList.print();

    // Exit Gracefully
    //
}
