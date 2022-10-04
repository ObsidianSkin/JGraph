CFLAGS ?= -std=c++11 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/maze 

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

bin/maze: src/maze.cpp
	g++ $(CFLAGS) -o bin/maze src/maze.cpp

