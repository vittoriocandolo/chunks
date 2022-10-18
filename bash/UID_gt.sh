line_number=$(wc -l < /etc/passwd)

if test $# -ne 1
    then
        echo "usage: $0 n"
        exit 1
fi

if test "$1" -lt -1
    then
        echo "usage: $0 n # n >= -1"
        exit 2
fi

i=1

while test $i -le "$line_number"
do
    line=$(sort -n -r -t: -k3,3 /etc/passwd | head -n +$i | tail -1)
    value=$(echo "$line" | cut -d: -f3)

    if test "$value" -gt "$1"
        then
            echo "$value"
        else
            exit 0
    fi
    i=$((i + 1))
done

exit 0

