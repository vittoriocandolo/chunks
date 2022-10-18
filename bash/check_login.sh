if (($# < 1))
    then
        echo "usage: $0 <string>"
        exit 1
fi

n=$#

for((i = 1; i <= n; i++))
do
    if grep "^$1:" /etc/passwd
        then
            id=$(grep "^$1:" /etc/passwd | cut -d':' -f3)
            echo "$1 ha UID $id"
        else
            echo "$1 non è un nome di login valido"
    fi
    shift
done

exit 0

