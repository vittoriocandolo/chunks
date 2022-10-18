#!/bin/bash

# given a .java input the comments are extracted
# and printed on the given output file

if (($# != 2))
    then
        echo "usage: jce <input file> <output file>" #jce = this
        exit 1
    elif [[ $1 != *.java ]]
        then
            echo "input file must be a java source file"
            exit 2
    else
        grep "//" "$1" > "$2" #dangerous
fi
exit 0

