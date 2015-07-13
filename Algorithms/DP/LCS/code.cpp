#include <stdio.h>
#include <string.h>

#define MAX 1001

using namespace std;

char word1[MAX];
char word2[MAX];
int common[MAX][MAX];

int LCS(){
	
	int L1 = strlen(word1);
	int L2 = strlen(word2);

	for(int i = 0; i < L1 ; i++)
		common[i][0] = 0;
	for(int i = 0; i < L2 ; i++)
		common[0][i] = 0;

	for(int i = 1 ; i <= L1 ; i++)
		for(int j = 1 ; j <= L2 ; j++){
			if(word1[i-1] == word2[j-1])
				common[i][j] = common[i-1][j-1] + 1;
			else
				common[i][j] = common[i-1][j] > common[i][j-1] ? common[i-1][j] : common[i][j-1];
		}
	return common[L1][L2];
}


int printLCS(int x){
    
	int L1 = strlen(word1);
	int L2 = strlen(word2);
	int j = L2 - 1;
	int i = L1 - 1;

	while( i >= 0 && j >= 0) {
		while(common[i][l] == x) j--;	
		printf("%c",word2[j+1]);
		i--;
	}
	printf("\n");
}

int main(){
	
	scanf("%s",word1);
	scanf("%s",word2);
	int answer = LCS();
	printf("%d\n",answer);	
	printLCS(answer);
	return 0;
}
