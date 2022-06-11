echo "Enter Binary Number: "
read bin
echo "Decimal Number: "
echo "obase=10; ibase=2; $bin" | bc
echo "Done"