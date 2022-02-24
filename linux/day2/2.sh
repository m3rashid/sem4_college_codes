echo "Enter a number: ";read n
echo "Binary: "
echo "obase=2;$n"|bc
echo "Octal: "
echo "obase=8;$n"|bc
echo "Hexadecimal: "
echo "obase=16;$n"|bc
