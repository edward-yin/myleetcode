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

$TOUCH $1/main.py
echo "#!/usr/bin/env python3" > $1/main.py
echo "# -*- coding: utf-8 -*-" >> $1/main.py
echo "" >> $1/main.py
echo "class Solution:" >> $1/main.py

echo "def main():" >> $1/main.py
echo "" >> $1/main.py
echo "if __name__ == "__main__":" >> $1/main.py
echo "    main()" >> $1/main.py



exit 0