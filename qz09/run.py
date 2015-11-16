#!/usr/bin/env python
import sys
import os

def main(argv):
    # create dictionary
    #
    fileDict = {}
    
    # open the file passed from the command line
    #
    with open(argv[1]) as f:
        # go through the file line by line
        #
        for line in f: 
           # split the line by the equal sign
           # where before equal sign is the variable name
           # and after equal sign is the value
           #
           [var, val] = line.split("=", 1)

           # add var and value pair to dictionary
           #
           fileDict[var] = val
     
    # Print entire dictionary
    #
    print("Entire dictionary contents gathered from input file")
    print(fileDict)
    
    print("\nEntire dictionary contents gathered from OS function")
    print(os.environ)
    print("\n------\n") 

    # Specifically looking at variable shell
    #
    print("From OS Function:")
    print "SHELL = %s\n" % (os.environ['SHELL'])
    print("From input file (x.txt)")
    print("SHELL = " + fileDict['SHELL'])

    # Exit Gracefully
    #
    print("Program Finished successfully.")
    
        
# Run main if tihs is ran as main function. 
if __name__ == "__main__":
    main(sys.argv)
