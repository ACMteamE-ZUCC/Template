#!/bin/sh
g++ -g gene.cpp -o gene
g++ -g run.cpp -o run
g++ -g std.cpp -o std
while true; do
  ./gene > input
  ./run < input > output
  ./std < input > answer
  if diff output answer; then
    echo Accepted
  else
    echo Wrong Answer
    break
  fi
done