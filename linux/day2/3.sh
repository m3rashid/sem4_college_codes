#  Write a shell script to accept a filename as input and remove all the lines containing the word "jamia" from that file

echo "Enter a file name"
read file
cat $file | grep -v "jamia" > out.txt
cat out.txt > $file