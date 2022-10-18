ids=$(cut -d':' -f3 /etc/passwd)
count=0

for i in $ids
do
    count=$((count+i))
done

echo $count

exit 0

