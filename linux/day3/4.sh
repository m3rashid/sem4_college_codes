echo "Enter the number: "; read n;
rev=0
while [ $n -gt 0 ]
do
  rev=`expr $rev \* 10 + $n % 10`
  n=`expr $n / 10`
done
echo "Reverse of $n is $rev"
