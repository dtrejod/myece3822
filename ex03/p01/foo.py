#!/usr/bin/env python
import os
import sys

# Import Class
#
from foo_00 import Vehicle

def readCars(fileName):
    # Check if file exsits
    #
    try:
        file = open(fileName, 'r')
    # Run this code if the open function throws an IOError
    #
    except IOError:
        print('There was an error opening the file \''+fileName+'\'')
        sys.exit(1)
    
    # Create a list of car objects
    #
    carList = []

    # For each line in our file
    #
    for lineO in file:
        # Strip line of leading/trailing space. Especially for that 
        # pesky new line character
        #
        lineO = lineO.strip()
        
        # Skip line if it is blank
        #
        if lineO == '':
            continue
        
        # Strip line into its words
        #
        lineList = lineO.split()
        # Create a new car object using values in our list
        #
        try:
            carX = Vehicle(lineList[2], lineList[3], lineList[4],
                    lineList[5])
        except ValueError:
            print("Error reading file")
            sys.exit(1)
        
        # Append current car object to the list
        #
        carList.append(carX)
       
    # Return to main function the list of cars
    #
    return carList

def printList(carList):
    # Loop through each item in the list and print
    for i in carList:
        i.debug()
    return

def main(argv):
    # Read in file
    #
    carList = readCars(argv[1])
    printList(carList)
    # Exit Gracefully
    #
    print("Program Finished successfully.")
   
    
# Run main if tihs is ran as main function. 
if __name__ == "__main__":
    main(sys.argv)
