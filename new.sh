#!/bin/bash

MKDIR=$(which mkdir)
# echo $MKDIR
TOUCH=$(which touch)
# echo $TOUCH
$MKDIR $1
$TOUCH $1/main.c

echo "#include <stdio.h>" > $1/main.c
echo "#include <string.h>" >> $1/main.c
echo "#include <stdlib.h>" >> $1/main.c
echo "#include <stdbool.h>" >> $1/main.c
echo "" >> $1/main.c

echo "int main()" >> $1/main.c
echo "{" >> $1/main.c
echo "" >> $1/main.c
echo "}" >> $1/main.c

exit 0