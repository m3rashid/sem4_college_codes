echo "Enter three numbers: "; read a b c
if [ $a -gt $b -a $a -gt $c ]; then 
  echo "Largest number is $a"
elif [ $b -gt $a -a $b -gt $c ]; then
  echo "Largest number is $b"
else echo "Largest number is $c"
fi