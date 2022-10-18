#!/bin/bash

# given two directories
# all content is copied from the first to the second one

if (($# == 2)) && test -d "$1" -a -d "$2"
    then
        cp -r "$1"/. "$2"
            : '
                for i in "$2"/*
                    do
                        sed s/SP/SU/g "$i" > "$i".tmp
                        cat "$i".new > "$i"
                        rm "$i".tmp
                    done
                '
    else
        echo "usage: dir_copy <dir_from> <dir_to>"
        exit 1
fi
exit 0

