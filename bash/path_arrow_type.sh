lista_file=$(find "$1")
l=$(echo $lista_file | wc -l)
i=1

while test $i -le "$l" # not best
do
    f=$(echo "$lista_file" | tail -n $i | head -1)
    echo -n "$f" '--> '
    if test -d "$f"
        then
            echo 'directory'
    fi
    if test -f "$f"
        then
            echo 'file'
    fi
    i=$((i + 1))
done

