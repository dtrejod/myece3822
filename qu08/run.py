#!/usr/bin/env python
import sys

def main(argv):
    # creat list to store numbers we find in file
    fileNums = []
    
    # open file
    with open(argv[1]) as f:
        # for each line in the file
        for line in f: 
            # extra the last word in the line
            word = line.rsplit(' ', 1)[-1]
            # try to append the last word to our numbered list
            try:
                # append last word to our list of numbers
                fileNums.append(float(word))
            except ValueError:
                pass

    # Sum numbers and print
    #
    print("sum of numbers in the file")
    print(sum(fileNums))
    
    # Exit Gracefully
    #
    print("Program Finished successfully.")
    
        
# Run main if tihs is ran as main function. 
if __name__ == "__main__":
    main(sys.argv)
