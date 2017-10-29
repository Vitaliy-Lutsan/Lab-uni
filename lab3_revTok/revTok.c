#include <stdio.h>
#include <string.h>
#define SIZE 256

int main (){
	printf("Enter a line of text\n");
	char input [SIZE];
	gets(input);
	int len = strlen(input);
	for (int i = len; i != 0; i--){
		if (input[i] == ' '){
			printf("%s ", &input[i+1]);
			input[i] = '\0';
		}
	}
	puts(input);
	return 0;
}