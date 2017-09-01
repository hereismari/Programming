#include <stdio.h>
#define MAX 10000
#define VALUE 51

using namespace std;

int n,q;
int x,r;
int action;

int m[MAX][MAX] = {0};

int max_line(int l){
	
	int cont[VALUE] = {0};
	for(int i = 0 ; i < n ; i++)
		cont[m[l][i]]++;

	int max_value = 0;
	for(int i = 0 ; i < VALUE ; i++)
		if(cont[i] >= max_value)
			max_value = i;

	return max_value;
}

int max_colum(int l){
	
	int cont[VALUE] = {0};
	for(int i = 0 ; i < n ; i++)
		cont[m[i][l]]++;

	int max_value = 0;
	for(int i = 0 ; i < VALUE ; i++)
		if(cont[i] >= max_value)
			max_value = i;
	return max_value;
}

void change_line(int l, int v){

	for(int i = 0 ; i < n ; i++)
		m[l][i] = v;
}

void change_colum(int l, int v){

	for(int i = 0 ; i < n ; i++)
		m[i][l] = v;
}

int main(){

	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < q ;i++){

		scanf("%d",&action);
		switch(action){
		
		case 1:
			scanf("%d %d", &x,&r);
			change_line(x-1,r);
			break;		
		case 2:
			scanf("%d %d",&x,&r);
			change_colum(x-1,r);
			break;
		case 3:
			scanf("%d",&x);
			printf("%d\n",max_line(x-1));
			break;
		case 4:
			scanf("%d",&x);
			printf("%d\n",max_colum(x-1));
			break;	
	}

}
	return 0;
}
