echo "Enter radius of circle: "
read r
area=$( echo "scale=2; 3.14*$r*$r" | bc )
echo "Area of circle is: $area"
per=$( echo "scale=2; 2*3.14*$r" | bc )
echo "Perimeter of circle is: $per"