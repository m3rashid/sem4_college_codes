clear
echo "Enter file name: "
read file
if [ -w $file ]
then
    echo "u have permission to write"
    cat >> $file
else
    echo "u don't have permission to write"
fi
