count=0

for i in /home/*
do
    if test -d "$i"
        then
            count=$((count + 1))
    fi
done

echo "Il numero di direcotry contenute in /home è $count"

exit 0

