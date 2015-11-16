#!/usr/bin/env python
import os
import sys

# Import Class
#
from foo_00 import wordCounts


def main(argv):

    # Create class object
    #
    myList = wordCounts() 

    # Read in file
    #
    myList.read(argv[1])
    #myList.saveData('eegs.pkl')
    myList.dropNotContain("Spike", True)
    myList.createHistogram(1)
    myList.createHistogram(2)
    #myList.myPrint()
    
    # Exit Gracefully
    #
    print("Program Finished successfully.")
   
    
# Run main if tihs is ran as main function. 
if __name__ == "__main__":
    main(sys.argv)
