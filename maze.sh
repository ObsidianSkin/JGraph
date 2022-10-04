#!/bin/sh

if [ $# -lt 2 ]
	then echo "usage ./maze.sh row col"
else
	bin/maze $1 $2 | jgraph -P | ps2pdf - | convert - maze.jpg
fi
