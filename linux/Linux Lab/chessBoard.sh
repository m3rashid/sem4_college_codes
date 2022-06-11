i=1
p=1
while [ $i -le 8 ]
do
    if [ $p -eq 1 ]
    then
        j=1
        while [ $j -le 8 ]
        do
            echo -n "***   "
            j=`expr $j + 1`
        done
        echo ""
        j=1
        while [ $j -le 8 ]
        do
            echo -n "***   "
            j=`expr $j + 1`
        done
    else
        j=1
        while [ $j -le 7 ]
        do
            echo -n "   ***"
            j=`expr $j + 1`
        done
         echo ""
        j=1
        while [ $j -le 7 ]
        do 
            echo -n "   ***"
            j=`expr $j + 1`
        done
    fi
    p=`expr 1 - $p`
    echo ""
    i=`expr $i + 1`
done