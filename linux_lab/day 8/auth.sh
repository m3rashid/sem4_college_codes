echo "======== MENU ========"
echo "1. LOGIN"
echo "2. REGISTER"
echo "3. CHANGE PASSWORD"
read -p "Choice: " choice

if [ $choice -eq "1" ]
then
  echo "Login here"
  read -p "Username: " username
  read -p "Password: " password
  if  grep -q $username username.txt; then echo "User found"
    if grep -q $password password.txt; then echo "Password Matched"
    else echo "Password not matched"
    fi
  else echo "User not found"
  fi
elif [ $choice -eq "2" ]
then
  echo "Register here"
  read -p "Username: " username
  read -p "Password: " password
  echo $username > username.txt
  echo $password > password.txt
  echo "User registered"
elif [ $choice -eq "3" ]
then
  echo "Change password here"
  read -p "Username: " username
  if grep -q $username username.txt
  then
    echo "Enter new password"
    read -p "Password: " password
    echo $password > password.txt
    echo "Password changed"
  else echo "User not found"
  fi
else echo "Invalid choice"
fi
