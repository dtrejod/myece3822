#!/bin/bash

# Assignment hw1 (part2):
# Count the total number of directories in the database. Count the total number 
#    of files. Count the number of sessions that have a first name that begins 
#    with “R” and a last name that begins with “S” and occurred between 2010 and
#    2013.

DATA_ECE_3822="/home/devin/projects/data/*";

# Count the total number of directories
echo "Total number of Dirs:"
ls -iR $DATA_ECE_3822 | wc -w

echo ""
# Count the number of files
echo "Total number of Files:"
find $DATA_ECE_3822 | wc -w

echo ""
# Count number of files that begin in "R" and "S" last name and 2010-13
echo "Number of Patients begin with R first name and last name S"
find $DATA_ECE_3822 -path '*/R*' | grep '_S' | grep '_2010\|_2011\|_2012\|_2013' |wc -w

echo ""
# Assignment hw1 (part3):
# Count the number of files in the database that have the word “spike” 
#    occurrinig at least once. Call this subset “A”. Repeat this for files 
#    containing the word “seizure,” which we will refer to as subset B. Produce
#    a histogram of the distribution of these words in subsets A and B, listing
#    the most frequently occurring first and least frequently occurring last. 
#    Show both the absolute counts and the percentage (often referred to as 
#    the cumulative distribution).

# grep
#    -i: ignore case
#    -R: recursive (search in sub-directories)
# cut -d: -f1 Source: Only print the filename of the occurance 
# sort | uniq: even if the word occured twice in one file only display it once.
#    We are looking for unique occurances
# <Source: http://www.cyberciti.biz/faq/howto-search-find-file-for-text-string/>

echo "Occurances of the word Spike:"
grep -iR 'spike' $DATA_ECE_3822 | cut -d: -f1 | sort | uniq | wc -w
echo "Occurances of the word Seizure:"
grep -iR 'seizure' $DATA_ECE_3822 | cut -d: -f1 | sort | uniq | wc -w

echo "Histogram of words with Spike|Seizure:"
grep -iR 'spike' $DATA_ECE_3822 | cut -d: -f1 | sort | uniq | wc -w

