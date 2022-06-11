echo "Enter Number in Decimal: "
read dec
a=1
bin=0
while [ $dec -gt 0 ]
do
    rem=$( echo $dec % 2 | bc )
    dec=$( echo $dec / 2 | bc )
    bin=$( echo $bin + $rem \* $a | bc )
    a=$( echo $a \* 10 | bc )
done
echo "Binary Number is: $bin"