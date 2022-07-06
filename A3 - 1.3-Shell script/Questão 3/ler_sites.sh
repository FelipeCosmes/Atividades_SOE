#!/bin/bash
arquivo='sites.txt'

while read linha; 
	do
	    wget $linha
	done < $arquivo
