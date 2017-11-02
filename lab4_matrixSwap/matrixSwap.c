#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MATRIXSIZE 10
#define VALUESIZE 100
#define SWAP(a,b) a^=b;b^=a;a^=b;

void displayMatrix(int (*matrix)[MATRIXSIZE]);
void swapRows(int (*matrix)[MATRIXSIZE], int row1, int row2);
void swapCols(int (*matrix)[MATRIXSIZE], int col1, int col2);

int main () {
	srand(time(NULL));
	int matrix [MATRIXSIZE][MATRIXSIZE], val1, val2;
	char input;

	for(int i = 0; i < MATRIXSIZE; i++){
		for(int j = 0; j < MATRIXSIZE; j++){
			matrix[i][j] = rand() % VALUESIZE;
		}
	}// Generating matrix
	printf("The matrix generated:\n\r");
	displayMatrix(matrix);
	do{
		printf("To swap rows, press R\n\rTo swap columns, press C\n\r");
		input = toupper(getchar());
	}while (input != 'R' && input !='C');
	switch (input){
		case 'R':
			printf("Enter index of first row to swap (0-%d): ", MATRIXSIZE-1);
			scanf ("%d", &val1);
			val1 %= MATRIXSIZE;
			printf("Enter index of second row to swap (0-%d): ", MATRIXSIZE-1);
			scanf ("%d", &val2);
			val2 %= MATRIXSIZE;
			if(val1 != val2){
				swapRows(matrix,val1,val2);
			}
			break;
		case 'C':
			printf("Enter index of first column to swap (0-%d): ", MATRIXSIZE-1);
			scanf ("%d", &val1);
			val1 %= MATRIXSIZE;
			printf("Enter index of second column to swap (0-%d): ", MATRIXSIZE-1);
			scanf ("%d", &val2);
			val2 %= MATRIXSIZE;
			if (val1 != val2){
				swapCols(matrix,val1,val2);
			}
			break;
	}
	displayMatrix(matrix);
	return 0;
}

void displayMatrix(int (*matrix)[MATRIXSIZE]){
	for(int i = 0; i < MATRIXSIZE; i++){
		for(int j = 0; j < MATRIXSIZE; j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n\r");
	}
}
void swapRows(int (*matrix)[MATRIXSIZE], int row1, int row2){
	for(int i = 0; i < MATRIXSIZE; i++){
		SWAP(matrix[row1][i],matrix[row2][i])
	}
}
void swapCols(int (*matrix)[MATRIXSIZE], int col1, int col2){
	for(int i = 0; i < MATRIXSIZE; i++){
		SWAP(matrix[i][col1],matrix[i][col2])
	}
}
