echo "Enter number: "
read num
count=0
while [ $num -ne 0 ]
do
    count=$((count+1))
    num=$((num/10))
done
echo "Number of digits: $count"