if cmp -s $1 $2
then
   echo 'The files have same content:'
   echo 'Deleting the second file from directory:'
   rm $2
else
    echo 'The files do not have same content'
fi
