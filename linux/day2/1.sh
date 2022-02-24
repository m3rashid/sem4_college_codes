hour=$(date +%H)

if [ $hour -lt 12 ]
then
	echo "Good morning"
elif [ $hour -lt 16 ]
then
	echo "Good afternoon"
elif [ $hour -lt 20 ]
then
	echo "Good evening"
else
	echo "Good night"
fi
