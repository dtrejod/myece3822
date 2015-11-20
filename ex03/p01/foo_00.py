#!/usr/bin/env python
import os

# PrimeDates Clas
#
class Vehicle():

    # Initialize Variables
    #
    def __init__(self, amanName = "-1", amodel = "-1", \
            awidth = -1, alength = -1):
        # Manufacturer name
        self.manName = amanName
        # Name of model
        self.model = amodel
        # Car width of wheel base
        self.width = awidth
        # Car length
        self.length = alength
    
    def debug(self):
        # Print the internal data of class
        print("Vehicle: ")
        print("\tManufacturer Name = " + self.manName)
        print("\tModel = " + self.model)
        print("\tWidth of the wheel base = " + str(self.width) + \
                " inches")
        print("\tLength of car = " + str(self.length) + \
                " inches")

