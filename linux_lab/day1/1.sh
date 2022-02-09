echo Enter the radius of circle: 
read r
area=$( echo 3.14 \* $r \* $r | bc )
perimeter=$( echo 2 \* 3.14 \* $r | bc )

echo Area of circle is $area
echo Perimeter of circle is $perimeter
