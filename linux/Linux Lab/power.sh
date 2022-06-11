echo "Enter Number: "
read num
echo "Enter power: "
read power
result=1
i=1
while [ $i -le $power ]
do
    result=$( echo $result \* $num | bc )
    i=$( echo $i + 1 | bc )
done
echo "Result is: $result"