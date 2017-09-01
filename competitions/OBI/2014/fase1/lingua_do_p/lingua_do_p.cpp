#include <stdio.h>
#include <iostream>
#include <string.h>

#define MAX 1001

using namespace std;

char input[MAX];
char output[MAX];

int main(){

	scanf("%[^\n]s",input);

	for(int i = 0,j =0, c= 1 ; i < strlen(input) ; i++){

		if(i % 2 == c)
		{
			output[j] = input[i];
			j++;
		}
		else if(input[i] == ' '){
			output[j] = ' ';
			j++;
			c = c == 1? 0:1;
		}
	}
	
	cout << output;

	return 0;
}
