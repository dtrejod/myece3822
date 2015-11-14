#!/usr/bin/env python
import os
import time
import re
import sys
import math
import unittest

# PrimeDates Clas
#
class PrimeDates():

    # Initialize Variables
    #
    def __init__(self):
        self.listDates = []
    
    def read(self, fileName):
        # Check if file exsits
        #
        try:
            file = open(fileName, 'r')
        # Run this code if the open function throws an IOError
        #
        except IOError:
            print('There was an error opening the file \''+fileName+'\'')
            sys.exit(1)

        # For each line in our file
        #
        for lineO in file:
            # Skip line if it is blank
            #
            # Strip line of leading/trailing space. Especially for that 
            # pesky new line character
            #
            lineO = lineO.strip()
            
            # Skip line if it is blank
            #
            if lineO == '':
                continue
           
            # Append to our class data list each line in the file
            #
            
            # First remove any special characters from the line using a
            # regex 
            #
            line = re.sub('[^a-zA-Z0-9-_*.]', '', lineO)
            
            # Append the dates to a list in datetime format
            #
            try:
                self.listDates.append(self.__loadDate__(line))
            except ValueError:
                print("There was an error recongizing the date " + \
                    lineO + ". Please make sure the month and date " + \
                    "is valid. (Note: A year is not required)")
                sys.exit(1)
    
    def __loadDate__(self, strDate):
        # We try to read the date time in multiple different formats
        #
        try: 
            return time.strptime(strDate,"%B%d%Y")
        except ValueError:
            # Pass the Value Error to the next exception
            #
            pass
        
        # Try to read with date in short month format
        #
        try:
            return time.strptime(strDate,"%b%d%Y")
        except ValueError:
            pass
       
        # Try to with data in short month format without year
        #
        try:
            return time.strptime(strDate,"%b%d")
        except ValueError:
            pass
        # Try to read the date without the year
        #
        try:
            return time.strptime(strDate,"%B%d")
        except ValueError:
            raise ValueError

    # Print to the console the contents of our list
    # by checking if it is a prime number
    #
    def convert(self):
        for item in self.listDates:
            # Get date from list in desired format
            #
            i = time.strftime("%j", item)
            
            # Check if prime number. Since i is a string we convert it to
            # a string. Using mod we can check if the number is divisble 
            # by two and thus a prime number.
            #
            if (self.__isprime__(int(i))):
                # If is a prime number print prime number message
                #
                print(time.strftime("%B %d", item) + " corresponds to " +\
                        "the integer " + i + ", and is a " + \
                        "prime number")
            else:
                # If is NOT a prime number print non-prime number 
                # message
                #
                print(time.strftime("%B %d", item) + " corresponds to " +\
                        "the integer " + i + ", and is not a " + \
                        "prime number")

    # We declare a 'private' python function to check if the number passed
    # is a prime number
    #
    def __isprime__(self,n):
        # Quick check to see if number is prime by checking if it divisble
        # by 2.
        #
        if n%2 == 0 and n > 2:
            return False
        # If quick check divisble by 2 is true then we will continue 
        # checking if the number is divisble up to the sqrt of the number
        # incremented in steps of 2.
        #
        for i in range(3, int(math.sqrt(n)) + 1, 2):
                if(n%i == 0):
                    return False
        # If after checking it is still not mod by 2 then we turn true
        #
        return True
