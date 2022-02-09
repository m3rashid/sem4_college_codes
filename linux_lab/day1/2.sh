echo Enter the length and breath of rectangle: 
read a b
area=$( echo "$a * $b" | bc)
perimeter=$( echo "2 * ($a + $b)" | bc )

echo Area of rectangle is $area
echo Perimeter of rectangle is $perimeter