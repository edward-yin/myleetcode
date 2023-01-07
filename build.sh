#!/bin/bash

cd $1
gcc -Wall -g -o main main.c
mv main ../bin/$1