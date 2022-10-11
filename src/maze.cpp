/* Blake Childress
 * CS 594 - Lab 1
 * This file generates a maze and visualizes solving it with jgraph.
 * 10/3/22
 */

#include <string>
#include <cstdio>
#include "disjoint_set.hpp"

using namespace std;

//TODO
//-implement disjoint sets
//	-using plank's implementation
//-create maze (Random Prim's algo)
//-solve maze

//helper to make maze (Prim's algo)
void makeMaze(int **board, int row, int col) {
	//inital board state (0/black = spot, 1/white = wall)
	int color = 0;
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < col; j++) {
			if (i % 2 != 0) color = 1;
			board[i][j] = color;
			color ^= 1;
		}
	}

	//create maze
}

//helper to draw board
void drawBoard(int **board, int row, int col) {
	//make a new graph with no axes
	printf("newgraph\n");
	printf("xaxis nodraw\n");
	printf("yaxis nodraw\n");

	//draw the board
	int color;
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < col; j++) {
			color = board[i][j];
			printf("newline poly color %1$d %1$d %1$d \
					pfill %1$d\n", color);
			//printf("newline poly pfill 0\n");
			printf("  pts %d %d  %d %d  %d %d  %d %d \n",
					  i, j, i+1, j, i+1, j+1, i, j+1);
		}
	}
}

//helpers for new and delete
int **newBoard(int row, int col) {
	int **board = new int *[row];
	for(int i = 0; i < row; i++) {
		board[i] = new int [col];
	}
	return board;
}

void deleteBoard(int **board, int row) {
	for(int i = 0; i < row; i++) {
		delete[] board[i];
	}
	delete[] board;
}
//end helpers

int main(int argc, char *argv[]) {
	//TODO
	//take user argument to solve maze or not?
	if(argc < 3) {
		printf("usage: bin/maze length width\n");
		return 1;
	}

	int **board, row, col;
	row = stoi(argv[1], NULL);
	col = stoi(argv[2], NULL);

	//offset for walls
	row += row - 1;
	col += col - 1;
	
	//allocate space for board
	board = newBoard(row, col);

	//initialize default values
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			board[i][j] = 0;
		}
	}

	//create the maze
	makeMaze(board, row, col);

	//generate jgraph
	drawBoard(board, row, col);

	//free board
	deleteBoard(board, row);

	return 0;
}
