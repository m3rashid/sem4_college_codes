echo "Enter the file name"
read file
if [ -w $file ]
then
  echo "You have write permissions on the file"
	cat >> $file
else
	echo "You don't have permission to write in this file or file doesnt exist"
fi