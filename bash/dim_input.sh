# legge da stdin, se diverso da fine stampa dim in byte
# e lunghezza in * (instogramma)

while true
do

    read line

    if test $line = 'fine'
        then
            exit 0
        else
            dim=$(echo $line | wc -c)
            dim=$((dim - 1)) #escludo new line

            for((i = 0; i < dim; i++))
            do
                echo -n '*'
            done

            if test $dim -gt 0
                then
                    echo
            fi
    fi
done

