if test $# -ne 2
then
    echo 'usage: listfiles <dirpath> <dimension>'
    exit 1
fi
if ! test -d $1
then
    echo 'usage: listfiles <dirpath> <dimension>'
    exit 1
fi
for i in $1/*
do
    if test -r $i -a -f $i
    then
        size=`wc -c < $i`
        if test $size -lt $2
        then
            echo `basename $i` has size $size bytes
        fi
    fi
done
exit 0

