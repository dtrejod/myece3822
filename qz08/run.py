#!/usr/bin/env python
import sys

def main(argv):
    # creat list to store numbers we find in file
    fileNums = []
    
    # open file
    with open(argv[1]) as f:

        while True:
            c = f.read(1)
            if not c:
                break
            # Check if number is a digit
            if c.isdigit():
                # if nunmber is digit add to list
                fileNums.append(int(c))
    
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
