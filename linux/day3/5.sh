echo "Enter the number: "; read n;
m=$n;
rev=0
while [ $n -gt 0 ]
do
  rev=`expr $rev \* 10 + $n % 10`
  n=`expr $n / 10`
done

if [ $rev -eq $m ]
then
  echo "$m is a palindrome"
else
  echo "$m is not a palindrome"
fi