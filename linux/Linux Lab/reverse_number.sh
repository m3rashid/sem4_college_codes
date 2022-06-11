echo "Enter Number: "
read num
rev=0
on=$num
while [ $num -gt 0 ]
do
    rem=`expr $num % 10`
    num=`expr $num / 10`
    rev=`expr $rev \* 10 + $rem`
done
echo "Reverse of $on is: $rev"