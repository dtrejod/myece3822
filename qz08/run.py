#!/usr/bin/env python
import sys

def main(argv):
    # creat list to store numbers we find in file
    fileNums = []
    
    # open file
    with open(argv[1]) as f:
        for line in f: 
            for t in line.split():
                try:
                    fileNums.append(float(t))
                except ValueError:
                    pass
            # Extract all numbers from this line
            #
            #if c.isdigit():
            #    # if nunmber is digit add to list
            #    fileNums.append(int(c))

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
