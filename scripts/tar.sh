if [ -e "$1.tar.gz" ]
then 
  rm -r "$1.tar.gz"
fi
tar --exclude="__pycache__" -cvzf "$1.tar.gz" $1
