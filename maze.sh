#!/bin/sh

if [ "$1" == "test" ]; then
	bin/maze 1 1 | jgraph -P | ps2pdf - | convert - maze1.jpg
	bin/maze 2 2 | jgraph -P | ps2pdf - | convert - maze2.jpg
	bin/maze 3 3 | jgraph -P | ps2pdf - | convert - maze3.jpg
	bin/maze 4 4 | jgraph -P | ps2pdf - | convert - maze4.jpg
	bin/maze 5 5 | jgraph -P | ps2pdf - | convert - maze5.jpg
elif [ $# -lt 2 ]
	then echo "usage ./maze.sh row col"
else
	bin/maze $1 $2 | jgraph -P | ps2pdf - | convert - maze.jpg
fi
