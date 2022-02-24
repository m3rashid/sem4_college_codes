echo "Enter a number: "; read n;
if [ $n -lt 0 ]
then
  echo "Factorial of $n is not possible"
else
  fact=1
  while [ $n -gt 0 ]
  do
    fact=`expr $fact \* $n`
    n=`expr $n - 1`
  done
  echo "Factorial of $n is $fact"
fi
