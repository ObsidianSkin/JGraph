CFLAGS ?= -std=c++11 -Wall -Wextra -Iinclude

ALL = bin/maze bin/dj_test

all: $(ALL)

clean:
	rm -f obj/* bin/*

bin/maze: src/maze.cpp
	g++ $(CFLAGS) -o bin/maze src/maze.cpp

obj/disjoint_set.o: src/disjoint_set.cpp include/disjoint_set.hpp
	g++ $(CFLAGS) -c -o obj/disjoint_set.o src/disjoint_set.cpp

obj/dj_test.o: src/dj_test.cpp include/disjoint_set.hpp
	g++ $(CFLAGS) -c -o obj/dj_test.o src/dj_test.cpp

bin/dj_test: obj/dj_test.o obj/disjoint_set.o
	g++ $(CFLAGS) -o bin/dj_test obj/dj_test.o obj/disjoint_set.o
