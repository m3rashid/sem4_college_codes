echo "Enter Number: "
read num
if [ $num -lt 0 ]
then
    echo "Factorial not defined for negative numbers"
else
f=1
i=1
while [ $i -le $num ]
do
    f=$( echo $f \* $i | bc )
    i=$( echo $i + 1 | bc )
done
echo "Factorial of $num is: $f"
fi