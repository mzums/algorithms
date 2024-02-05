#!/bin/bash

g++ -g -o main main.cpp
g++ -g -o gen gen.cpp
g++ -g -o main2 main2.cpp

for t in {1..1000} ; do
    echo test ${t}
    ./gen > tmp/wejscie.in
    echo "My code running..."
    ./main < tmp/wejscie.in > tmp/moje.out
    echo "My code ended with code 200"
    echo "Running not my"
    ./main2 < tmp/wejscie.in > tmp/poprawne.out
    echo "Not my ended with code 200"
    diff -bew tmp/moje.out tmp/poprawne.out || { echo ":(" ; break; }
    echo -e "OK\n"
done
