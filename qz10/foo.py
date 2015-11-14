#!/usr/bin/env python
import os
import sys

# Import Class
#
from foo_00 import PrimeDates


def main(argv):

    # Create class object
    #
    myDates = PrimeDates() 

    # Read in file
    #
    myDates.read(argv[1])
    myDates.convert()
    myDates.myPrint()

    # Exit Gracefully
    #
    print("Program Finished successfully.")
   
    
# Run main if tihs is ran as main function. 
if __name__ == "__main__":
    main(sys.argv)
