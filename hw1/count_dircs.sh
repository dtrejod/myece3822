#!/bin/bash

# Assignment hw1 (part2):
# Count the total number of directories in the database. Count the total number 
#     of files. Count the number of sessions that have a first name that begins 
#     with “R” and a last name that begins with “S” and occurred between 2010 and 2013.

DATA_ECE_3822="/home/devin/projects/data/*";

# Count the total number of directories
echo "Total number of Dirs:"
ls -d $DATA_ECE_3822 | wc -w

echo ""
# Count the number of files
echo "Total number of Files:"
find $DATA_ECE_3822 | wc -w

echo ""
# Count number of files that begin in "R" and last name "S"
echo "Number of Patients begin with R first name and last name S"
find $DATA_ECE_3822 -type f -iname "R*" | find -iname "*_S*"
