#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct data {
	int n_color;
	int n_size;
	char name[100];
	char color[100];
	char size[100];
	
	data(){};

	data(char n[100], char c[100], char s[100]){
		if(strcmp(c,"branco") == 0) n_color = 0;
		else n_color = 1;

		if(strcmp(s,"P")==0) n_size = 0;
		else if (strcmp(s,"M")==0) n_size = 1;
		else n_size = 2;

		strcpy(name,n);
		strcpy(color,c);
		strcpy(size,s);
	}

};

bool comp(data a, data b) { 
	if(a.n_color != b.n_color) return a.n_color < b.n_color;
	if(a.n_size != b.n_size) return a.n_size < b.n_size;
	return strcmp(a.name,b.name) <= 0;
}

data camisas[10000];
int n;
char name[100];
char size[100];
char color[100];
int main(){

	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		for(int i = 0 ; i < n; i++){
			scanf("\n%[^\n]s",name);
			scanf("\n%s %s",color,size);
			camisas[i] = data(name,color,size);
		}

		sort(camisas,camisas + n,comp);
		for(int i = 0 ; i < n ; i++)
			printf("%s %s %s\n",camisas[i].color,camisas[i].size,camisas[i].name);		
			printf("\n");
	}	
	return 0;
}
