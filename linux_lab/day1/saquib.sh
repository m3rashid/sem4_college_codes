echo Enter your detail
read user
read password

if ($user == "admin") &&($password == "abc123")
then 
  echo "loggedin!"
else
  echo "invalid username or password"
fi
