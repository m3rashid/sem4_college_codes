# shell script to remove the temporary files from the current working directory

for a in *.tmp
do
  rm $a
done