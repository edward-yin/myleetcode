#!/bin/bash

/usr/bin/mkdir $1
/usr/bin/touch $1/main.c

echo "#include <stdio.h>" > $1/main.c
echo "#include <string.h>" >> $1/main.c
echo "#include <stdlib.h>" >> $1/main.c
echo "" >> $1/main.c

echo "int main()" >> $1/main.c
echo "{" >> $1/main.c
echo "" >> $1/main.c
echo "}" >> $1/main.c

exit 0