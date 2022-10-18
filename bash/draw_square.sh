if test $# -ne 1
then
	echo 'usage: drawSquare <n>'
e	xit 1
fi
if test $1 -lt 2 -o $1 -gt 15
then
	echo 'param must be number ]1,16]'
	exit 2
fi
x=$1
y=$1
while test $y -gt 0
do
	while test $x -gt 0
	do
		if test $x -eq 1 -o $x -eq $1
		then
			if test $y -eq 1 -o $y -eq $1
			then
				echo -n "+"
			else
				echo -n "|"
			fi
		else
			if test $y -eq 1 -o $y -eq $1
			then
				echo -n "-"
			else
				echo -n " "
			fi
		fi
		x=$[$x-1]
	done
	x=$1
	y=$[$y-1]
	echo
done
exit 0

