#!/bin/bash
up()
{
	for i in $(seq $1)
    do
        pwd
        cd ..
        pwd
    done
}

n_up=$1
up $n_up
