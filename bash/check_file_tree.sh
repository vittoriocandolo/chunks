if ! test $# -eq 1 -a -d "$1"
    then
        echo "usage: $0 pathname"
        exit 1
fi

num_file=0
num_dir=0
list=$(find "$1" -print 2>/dev/null)

for i in $list
do
    if test -f "$i"
        then
            num_file=$((num_file + 1))
    fi
    if test -d "$i"
        then
            num_dir=$((num_dir + 1))
    fi
done

echo "Numero di file: $num_file"
echo "Numero di directory: $num_dir"

exit 0

