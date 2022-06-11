echo "Enter First Number"
read a
echo "Enter Second Number"
read b
gcd=1
i=1
while [ $i -le $a ]
do
if [ `expr $a % $i` -eq 0 -a `expr $b % $i` -eq 0 ]
then
gcd=`expr $gcd \* $i`
fi
i=`expr $i + 1`
done
echo "GCD of $a and $b is $gcd"