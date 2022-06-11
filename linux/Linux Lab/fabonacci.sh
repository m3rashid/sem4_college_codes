echo "Enter fabonacci range"
read n
a=0
b=1
echo "Fibonacci series is:"
echo $a
echo $b
i=2	
while [ $i -lt $n ]
do
    c=$( echo $a + $b | bc )
    echo $c
    a=$b
    b=$c
    i=$( echo $i + 1 | bc )
done