#!/bin/bash

# given a directory and a file size in bytes
# returns list of files smaller than the given value
# from the given directory

if (($# != 2))
    then
        echo "usage: file_size <dir> <size>"
        exit 1
    elif ! test -d "$1"
        then
            echo "usage: file_size <dir> <size>"
            exit 1
    else
    for i in "$1"/*
        do
            if test -r "$i" -a -f "$i"
                then
                    if test "$(wc -c <"$i")" -lt "$2"
                        then
                            echo "$(basename "$i")"
                    fi
            fi
        done
fi
exit 0

