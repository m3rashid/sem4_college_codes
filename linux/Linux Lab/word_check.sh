echo "Enter Word: "
read word
case $word in
    [aeiou]*)
        echo "word starts with lowercase vowel"
        ;;
    [AEIOU]*)
        echo "word starts with uppercase vowel"
        ;;
    ???)
        echo "3 letter word"
        ;;
    *)
        echo "default case"
        ;;
esac