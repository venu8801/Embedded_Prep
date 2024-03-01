/* 36. Valid Sudoku
Medium
Topics
Companies

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
*/

#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
	if(board == NULL)
		return false;

	int arr[9] = {0}; //to find repeatative numbers

	int i,j,k;

	//checking all rows
	for(i = 0; (i < boardSize) ; i++)
	{
		for(k = 0; k < *boardColSize; k++){

			if(board[i][k] == '.') //skip iteration
				continue;  
			for(s = 0; s < 9; s++) //init array with zeroes
				arr[s] = 0;
			if(board[i][k] >= '1' && board[i][k] <= '9'){
				arr[board[k][i] - 1]++;
				for(s = 0; s < 9; s++){
					if(arr[s] > 1)
						return false;
				}

			}

		}
	}
	//check all columns
	for(k = 0; k < *boardColSize; k++ ){
		
		for(j = 0; j < boardSize; j++){
		
			if(board[j][k] == '.')
				continue;
			for(s = 0; s < 9;s++)
				arr[s] = 0;
			if(board[j][k] >= '1' && board[i][k] <= '9')
				arr[board[k][i] - 1]++;
			for(s = 0; s < 9; s++){
				if(arr[s] > 1)
					return false;
			}


		}
	}

	//check 3x3 matrix
	for(i = 0; i < 9; i++)
	{
		for(k = 0; k < 3; k++)	{
			for(m = 0; m < )

		}



	}
	
}
