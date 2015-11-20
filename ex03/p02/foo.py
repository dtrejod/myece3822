#!/usr/bin/env python
import os
import sys
import pickle

def main(argv):
    # Get path of the run program 
    #
    myPath = os.path.dirname(os.path.realpath(__file__))
    
    # The file name for saving value of previous run
    #
    fName = ".preRunSum.txt"

    # Full filepath
    #
    fullFPath = os.path.join(myPath, fName)

    # Create a list
    #
    numList = []
    # Read in file skipping for argument
    #
    for arg in argv[1:]:
        numList.append(int(arg))
    # Sum list
    #
    curSum = sum(numList)

    if os.path.isfile(fullFPath):
        preSum = int(open(fullFPath, 'r').read())
        curSum = curSum + preSum
    
    # Print to console the sum
    #
    print("Sum = " + str(curSum))

    # Save to file the sum
    #
    myFile = open(fullFPath, 'w')
    myFile.write(str(curSum))
    myFile.close()

    # Save cursum to file
    # Exit Gracefully
    #
    print("Program Finished successfully.")
   
    
# Run main if tihs is ran as main function. 
if __name__ == "__main__":
    main(sys.argv)
