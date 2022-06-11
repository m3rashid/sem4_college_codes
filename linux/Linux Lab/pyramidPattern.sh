echo Enter the limit
read limit
echo pattern
i=1
while [ $i -le $limit ]
do
j=`expr $limit - $i`
while [ $j -gt 0 ]
do
echo -n " "
j=`expr $j - 1`
done
j=1
while [ $j -le $i ]
do
echo -n "* "
j=`expr $j + 1`
done
echo
i=`expr $i + 1`
done