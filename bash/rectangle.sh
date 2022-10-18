#!/bin/bash

# given an integer between 2 and 16 draws a square on the terminal

if test $# -eq 1
    then
        if test "$1" -ge 2 -a "$1" -le 16
            then
                centerino=$(($1 - 2))
                #echo $centerino
                echo -n "+"
                for ((i = 0; i < centerino; i++))
                    do
                        echo -n "-"
                    done
                echo -n "+"
                echo ""
                for ((i = 0; i < centerino; i++))
                    do
                        echo -n "|"
                        for ((j = 0; j < centerino; j++))
                            do
                                echo -n " "
                            done
                        echo "|"
                    done
                echo -n "+"
                for ((i = 0; i < centerino; i++))
                    do
                        echo -n "-"
                    done
                echo -n "+"
                echo ""
            else
                echo "given dimension should be between 2 and 16"
                exit 1
        fi
    else
        echo "usage: rectangle <dim>"
        exit 1
fi
exit 0

