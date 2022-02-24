echo "Enter a word: "; read word;

case $word in 
  [aeiou]* ) echo "The word begins with a lowercase vowel.";;
  [AEIOU]* ) echo "The word begins with an uppercase vowel.";;
  *[0-9]) echo "The word ends with a number.";;
  ???) echo "You entered three letter word.";;
  * ) echo "You entered an unhandled word.";;
esac
