#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
unsigned long bitSwap (unsigned long number, unsigned long i, unsigned long j);
unsigned long bitSwap2 (unsigned long number, unsigned long i, unsigned long j);

int main(int argc, char *argv[]) {
	unsigned long i,j,n;
	printf("Please enter the number and indexes of two bits to swap\n");
	scanf("%lu %lu %lu", &n, &i, &j);
	printf("%lu\n", bitSwap(n, i, j));
	printf("%lu\n", bitSwap2(n, i, j)); //debug to check if Bitswap 2 also works
	getch();
	return 0;
}

unsigned long bitSwap (unsigned long number, unsigned long i, unsigned long j){
	
	unsigned long x = ((number >> i) ^ (number >> j)) & 1; // XOR temporary
	return number ^ ((x << i) | (x << j));
}

unsigned long bitSwap2 (unsigned long number, unsigned long i, unsigned long j){

	unsigned long bit_i = (number >> i) & 1;
	unsigned long bit_j = (number >> j) & 1;
	unsigned long number_tmp = number & ~((1 << i) | (1 << j));
	unsigned long matrix = (bit_i << j) | (bit_j << i);
	return number_tmp | matrix;
}
