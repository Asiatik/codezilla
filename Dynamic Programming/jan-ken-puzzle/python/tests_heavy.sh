#!/bin/bash
shopt -s nullglob
TIMEFORMAT='%3R'

for ext in .in; do
    files=(test/heavy/*"$ext")
    for i in `seq -f %02g ${#files[@]}`; do
        printf "\n$i,";
        time (python3 puzzle_hash.py < test/heavy/$i.in | tee test/heavy/results$i &> /dev/null);
        # printf "\n";
        # diff -y test/heavy/results$i test/heavy/$i.out;
    done
done
