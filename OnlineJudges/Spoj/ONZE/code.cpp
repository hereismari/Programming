#include <stdio.h>
#include <string.h>
#define MAX 1000000

using namespace std;

char s[MAX];

int main(){

	while(1){
		int answer = 0;
		scanf("%s",s);
		if(strcmp(s,"0") == 0) break;
		for(int i = strlen(s)-1 ; i >=0 ; i--)
			if(i%2==0)
				answer += s[i] - '0';
			else
				answer -= s[i] - '0';
		if(answer % 11 == 0) printf("%s is a multiple of 11.\n",s);
		else printf("%s is not a multiple of 11.\n",s);
	}
	return 0;
}
