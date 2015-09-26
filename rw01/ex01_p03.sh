#!/bin/bash

# Obtain OS and Processor uning uname
# Export values and echo them to the enviorment. 
export MY_OS=$(uname -o)
echo $MY_OS
export MY_PROC=$(uname -p)
echo $MY_PROC
