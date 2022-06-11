count =0 
echo "Files having size greater than 1000 bytes"
echo "File Name"
for i in $(ls -S)
do
    if [ -f $i ]
    then
        size=$(stat -c%s $i)
       if [ $size -gt 1000 ]
       then
           echo $i
           count=$((count+1))
       fi
    fi
done
echo "Total number of files having size greater than 1000 bytes are $count"