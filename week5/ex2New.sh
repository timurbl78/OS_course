txt="ex2.txt"
lock="ex2.lock"

if ln $txt $lock;
then
  for i in `seq 1 5000`;
  do
    num=$(tail -n 1 < $txt)
    expr $num + 1 >> $txt
  done

  rm $lock
fi

# modified with lock-file
# critical region - access to the same file
