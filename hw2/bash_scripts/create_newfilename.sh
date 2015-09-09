#!/bin/bash

# Assignment hw2 (Part 2)
# The shellscript “myscript.sh” is a program, using bash programming, that 
#    converts filenames like:
#        /isip/data/tuh_eeg/data/book_13/012345678_20130101/Jones_John/eg_00.txt#    to filenames like:
#        /usr/tmp/joe_000027.txt

# 'sed' replaces all characters before _eg with the string contained in the second arugment
# awk appends the line number to the end of the file

# $1 : First arugment in a input file that contains a listing of all files 
# $2 : Second arugment is a string that will become the output. For example '/usr/tmp/joe_

sed 's|.*eg_.*|'$2'|' $1 | awk '{printf("%s%05d.txt\n",$0, NR)}'

