echo "Enter the username": 
read username

who > list.txt
if grep -q $username list.txt
then
  echo "User is logged in"
else
  echo "User is not logged in"
fi
