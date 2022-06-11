for x in $*
do 
  if [ -f $x ]
  then
    echo " $x is  a file "
    echo " no of lines in the file are "
    wc -l < $x
  else 
    if [ -d mydir ]
    then
      echo "mydir exists"
      echo " Number of files in mydir "
      ls mydir | wc -l
    else 
      mkdir mydir 
    fi
  fi
done
