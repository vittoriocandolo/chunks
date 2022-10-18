if ! test $# -eq 1 -a -d "$1"
    then
        echo "usage: $0 pathname"
        exit 1
fi

dim_tot=0

list=$(find "$1" -print 2>/dev/null)

for i in $list
do
    if test -f "$i"
        then
            echo "$i, $(wc -c $i | cut -d' ' -f1) byte"
            dim_tot=$((dim_tot + $(wc -c $i | cut -d' ' -f1)))
    fi
done

echo "Totale dei byte occupati: $dim_tot"

exit 0

