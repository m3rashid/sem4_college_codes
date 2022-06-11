a=`echo $$`
echo "PID of current Shell: $a"
for i in *.*
do 
    t=`echo $i | cut -f2 -d"."`	
    if [ $t = $a ]
    then
        echo "Shell PID sucessfully removed from file $i and renamed as `basename $i .$t`"
        mv $i `basename $i .$t`
    fi
done