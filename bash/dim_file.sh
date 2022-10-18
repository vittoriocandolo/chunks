if test $# -ne 1
    then
        echo "Utilizzo: $0 <file>"
        exit 1
fi

if test -f $1 -a -r $1
    then
        dim=$(wc -c < $1)
        echo "Dimensione di $1: $dim byte"

        i=0

        while test $i -lt $dim
        do
            echo -n '*'
            i=$((i + 1))
        done

        if test $dim -gt 0
            then
                echo
        fi

    else

        echo "Il file passato deve esistere, esser leggibile e regolare"
        exit 2
fi

exit 0

