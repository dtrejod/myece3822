#!/usr/bin/env python
import os
import time
import re

class PrimeDates():

    # Initialize Variables
    #
    def __init__(self):
        self.listRawDates = []
        self.listDates = []
    
    def read(self, fileName):
        # For each line in our file
        #
        for line in open(fileName, 'r'):
            # Append to our class data list each line in the file
            #
            self.listRawDates.append(line.rstrip())

    def convert(self):
        # For each value in stored in our list
        #
        for line in self.listRawDates:
            re.sub('[^a-zA-Z0-9-_*.]', '', line)
            self.listDates.append(time.strptime(line, "%B %d, %Y"))

    def myPrint(self):
        for item in self.listDates:
            print(time.strftime("%j", item))

