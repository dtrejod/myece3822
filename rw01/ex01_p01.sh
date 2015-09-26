#!/bin/bash

# Re-Exam 1 Problem 1
# grep
#    -i: ignore case
#    -R: recursive (search in sub-directories)
#    -w: match whole word
#    -l: stop searching the file once a match is found (avoid duplicates)
# <Source: http://www.cyberciti.biz/faq/howto-search-find-file-for-text-string/>

# Data Folder Location
DATA_ECE_3822="/home/devin/projects/data/";

# Find files year 2007 in month of May w/ words spike and sustained
find $DATA_ECE_3822 -type f -path '*_200705*' -exec grep -iwlE 'sustained.*spike|spike.*sustained' {} \; > subseta.list

