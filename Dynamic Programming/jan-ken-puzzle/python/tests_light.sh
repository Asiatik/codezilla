#!/bin/bash
shopt -s nullglob
TIMEFORMAT='%3R'

for ext in .in; do
    files=(test/light/*"$ext")
    for i in `seq -f %02g ${#files[@]}`; do
        printf "\n$i,";
        time (python puzzle_hash.py < test/light/$i.in | tee test/light/results$i &> /dev/null);
        # printf "\n";
        # diff -y test/light/results$i test/light/$i.out;
    done
done
