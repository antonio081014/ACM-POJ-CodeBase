#!/bin/sh

if [ $# -lt 2 ]
then 
	echo "There should be more than two arguments needed."
	exit 0
fi

for i in "$@"
do
	STR=$STR\_$i
done

echo -n "//" >> poj$STR\.cpp
date >> poj$STR\.cpp
cat Temple >> poj$STR\.cpp
#mv poj$STR\.cpp POJ_Judge/
