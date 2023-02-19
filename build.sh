#!/bin/bash

cd $1
gcc -Wall -g -o main main.c -lm -std=c99 -I../include
mv main ../bin/$1