#!/bin/bash

# given a directory as a starting point
# the script deletes all the files named 'core'
# down along the directory tree

if test $# -eq 1 -a -d "$1"
    then
        for i in $(find . | grep -w core)
            do
                rm "$i"
            done
    else
        echo "usage: core_killer <starting_directory>"
        exit 1
fi
exit 0

