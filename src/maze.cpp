/* Blake Childress
 * CS 594 - Lab 1
 * This file generates a maze and visualizes solving it with jgraph.
 * 10/3/22
 */

#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime> //for seeding random
#include "disjoint_set.hpp"

using namespace std;

//TODO
//-implement disjoint sets
//	-using plank's implementation
//	-not actually going to use it?
//-create maze (Random Prim's algo)
//	-how to determine walls for size > 10?
//-solve maze

vector<string> walls; //strings of wall location (e.g., "01" = row 0 & col 1)

//helper to add walls to list
void addWalls(int max_row, int max_col, int cur_row, int cur_col) {
	//check top
	if(cur_row + 1 < max_row) walls.push_back(to_string(cur_row + 1) + to_string(cur_col));

	//check bot
	if(cur_row - 1 > 0) walls.push_back(to_string(cur_row - 1) + to_string(cur_col));
	
	//check left
	if(cur_col - 1 > 0) walls.push_back(to_string(cur_row) + to_string(cur_col - 1));
	
	//check right
	if(cur_col + 1 < max_col) walls.push_back(to_string(cur_row) + to_string(cur_col + 1));
}

//helper to make maze (Prim's algo)
void makeMaze(int **board, int row, int col) {
	//inital board state (0/black = spot, 1/white = wall)
	//int color = 0;
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < col; j++) {
			board[i][j] = 0;
		}
	}

	//get starting position (must convert back to original row/col size
	//	+ only get even positions)
	int start_row = 2 * (rand() % (((row - 1) / 2) + 1));
	int start_col = 2 * (rand() % (((col - 1) / 2) + 1));

	board[start_row][start_col] = 1; //mark as part of maze

	addWalls(row, col, start_row, start_col); //add walls to wall list

	//test
	/*printf("start: %d %d\n", start_row, start_col);
	for(int i = 0; i < walls.size(); i++) {
		printf("%s\n", walls.at(i).c_str());
	}*/
	
	//while still walls in list
	while(walls.size() > 0) {
		int rand_wall = rand() % walls.size(); //pick a random wall
		string wall = walls.at(rand_wall);

		//printf("%s ", wall.c_str());
		//check cells on either side
		int wall_row = wall[0] - '0';
		int wall_col = wall[1] - '0';
		//printf("%d %d ", wall_row, wall_col);
		if(wall_col % 2 == 0) {
			//if col is even, check vertical
			//printf("horizontal\n");
			//if only one is set
			if(board[wall_row - 1][wall_col] ^ board[wall_row + 1][wall_col]) {
				board[wall_row][wall_col] = 1; //mark wall as visited
				
				//mark adjacent node as visited plus add neighboring walls to list
				if(!(board[wall_row - 1][wall_col])) { //check left
					board[wall_row - 1][wall_col] = 1; 
					addWalls(row, col, wall_row - 1, wall_col);
				} else { //check right
					board[wall_row + 1][wall_col] = 1;
					addWalls(row, col, wall_row + 1, wall_col);
				}
			} //else printf("double horizontal\n");
		} else if(wall_row % 2 == 0) {
			//if row is even, then check horizontal
			//printf("verical\n");
			//if only one is set
			if(board[wall_row][wall_col - 1] ^ board[wall_row][wall_col + 1]) {
				board[wall_row][wall_col] = 1; //mark wall as visited
				
				//mark adjacent node as visited plus add neighboring walls to list
				if(!(board[wall_row][wall_col - 1])) { //check down
					board[wall_row][wall_col - 1] = 1; 
					addWalls(row, col, wall_row, wall_col - 1);
				} else { //check up
					board[wall_row][wall_col + 1] = 1;
					addWalls(row, col, wall_row, wall_col + 1);
				}
			} //else printf("double vertical\n");
		} else {
			printf("%d %d\n", wall_row, wall_col);
		}

		//printf("%d %s\n", rand_wall, walls.at(rand_wall).c_str());

		walls.erase(walls.begin() + rand_wall); //remove it from list
	}
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
			color = board[i][j] ^ 1; //^ 1 to flip color
			printf("newline poly color %1$d %1$d %1$d \
					pfill %1$d\n", color);
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

	srand(time(NULL)); //testing

	//offset for walls
	row += row - 1;
	col += col - 1;
	
	//allocate space for board
	board = newBoard(row, col);

	//create the maze
	makeMaze(board, row, col);

	//generate jgraph
	drawBoard(board, row, col);

	//free board
	deleteBoard(board, row);

	return 0;
}
