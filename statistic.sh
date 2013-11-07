#!/bin/bash
rm -rf hello
for folder in Volumn_*
do
	echo $folder:
	ls  $folder/ | wc -w 
done
