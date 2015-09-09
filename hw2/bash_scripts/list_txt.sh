#!/bin/bash

# Assignment hw2 (part1):
#    Create a list of all *.txt files.

DATA_ECE_3822=$HOME/projects/data/;

find $DATA_ECE_3822 -iname "*.txt"
