#!/bin/bash

# given a string and a file return the string if found in the file

if (($# != 2))
    then
        echo 'usage: string-finder <string> <file>'
        exit 1
    else
        grep -w "$1" "$2" # | wc -l
fi
exit 0

