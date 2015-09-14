#!/bin/bash

# $1 : Argument 1 - Name of file you want to copy
# $2 : Argument 2  Number of copies of the file you want

INPUT=$1 
for num in $(seq -w 1 $2)
do
    cp "$INPUT" "${INPUT%.mp3}"$num".mp3"
done
