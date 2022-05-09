for i in $(seq 1 8)
do
    echo -n "|"
	for j in $(seq 1 8)
	do
		S=$(((i+j)%2))
		if [ $S -eq 0 ]
		then
			echo -n "0|" 
		else
			echo -n "1|"
		fi
	done
	echo -n "1|" 
	echo ""
done
