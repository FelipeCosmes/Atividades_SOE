#!/bin/bash
for i in {1..100}
do 
	touch teste$i.txt
	echo 'Número do arquivo =' $i >> teste$i.txt
done
