echo "Enter the number: "; read n;
product=1
while [ $n -gt 0 ]
do
  remainder=`expr $n % 10`
  product=`expr $product \* $remainder`
  n=`expr $n / 10`
done
echo "Product of digits of $n is $product"
