echo "Enter the number: "; read decimal;
a=1;
binary=0;
while [ $decimal -gt 0 ]
do
  rem=$(( $decimal % 2 ));
  binary=$(( $binary + $rem * $a ));
  decimal=$(( $decimal / 2 ));
  a=$(( $a * 10 ));
done

echo "The binary equivalent is: $binary";