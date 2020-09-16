for i in `seq 1 5000`;
  do
    # critical region starts
    num=$(tail -n 1 < ex2.txt)
    expr $num + 1 >> ex2.txt
  done