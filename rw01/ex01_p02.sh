#!/bin/bash

# Re-Exam 1 Problem 2

# Data Folder Location
DATA_ECE_3822="/home/devin/projects/data/";

# Generate a list of files whose paths contains John
find $DATA_ECE_3822 -type f -path '*John*' > subset2a.list

# Loop through each line in the subset
# Source: http://www.cyberciti.biz/faq/bash-loop-over-file/
totalchars=0
count=0
while IFS= read -r file
do
    echo $file
    echo "Number of characters"
    chars=`wc -m $file | cut -f1 -d ' '`
    echo $chars
    
    totchars=$((totchars + chars))
    count=$((count + 1))
    echo ""
done < "subset2a.list"

echo ""
echo "Total Number of files processed"
echo $count
echo ""
echo "Total Number of characters in files"
echo $totchars
