if test $# -ne 2
then
	echo 'usage: spToSu <dir1> <dir2>'
	exit 1
fi
if ! test -d $1 -a -d $2
then
	echo '$1 and $2 must be directories'
	exit 2
fi
for i in $1/*
do
	sed "s/SP/SU/g" "$i" > $2/‘basename $i‘
done
exit 0

# Alternative

for i in ‘find $1 -type f‘
do 
	sed "s/SP/SU/g" "$i" > $2/‘basename $i‘
done
exit 0

