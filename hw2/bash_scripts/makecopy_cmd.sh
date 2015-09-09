#!/bin/bash

# Assignment hw2 (Part 2b)
# The output file, “x.sh”, will look like this:
#    #my shellscript
#    cp <first filename on your list> /usr/tmp/joe_000000.txt
#    cp <second filename on your list> /usr/tmp/joe_000001.txt
#    cp <third filename on your list> /usr/tmp/joe_000002.txt

# This 'sed' command appends text to the beginining of each line_

# $1 : First arugment is the source directory
# $2 : Second arugment is the output directory

paste $1 $2 > ._tmp_txt_files.list
sed 's|^|cp |' ._tmp_txt_files.list

rm ._tmp_txt_files.list
