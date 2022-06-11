echo "Enter length of rectangle: "
read length
echo "Enter width of rectangle: "
read width
area=$( echo $length \* $width | bc )
perimeter=$( echo 2 \* $length + 2 \* $width | bc )
echo "Area of rectangle is $area"
echo "Perimeter of rectangle is $perimeter"