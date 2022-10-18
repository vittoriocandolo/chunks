if test $# -ne 1
then
	echo 'usage: rmCore <dir>'
	exit 1
fi
if ! test -d $1
then
	echo '$1 must be directory'
	exit 2
fi
find $1 -name core -exec rm {} \; 2>/dev/null
exit 0

