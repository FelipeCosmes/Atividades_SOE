#!/bin/bash/

for i in $(seq 1 2 $#)
	
do

	cal ${@:i:2}

done
