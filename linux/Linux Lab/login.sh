echo "Enter username: "
read username
echo "Enter password: "
read password
if [ $username = "admin" ] && [ $password = "abc123" ]; then
    echo "Welcome $username"
else
    echo "Wrong username or password"
fi