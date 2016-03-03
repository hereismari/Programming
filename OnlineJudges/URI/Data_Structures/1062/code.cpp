#include <stdio.h>
#include <stack>
#define MAX 100000

using namespace std;

int n;
int a[MAX];
stack<int> pilha;
int tmp[MAX];
int r[MAX];
bool can;

int main(){

	while(1){

		scanf("%d",&n);
		if(n == 0) break;
		while(1){
			for(int i = 0 ; i < n ; i++){
				tmp[i] = i+1;
				scanf("%d",&a[i]);
				if(a[i] == 0) break;
			}
			
			if(a[0] == 0) 
				{ printf("\n"); break;}
			int i = 0;
			int j = 0;
		while ( ! pilha.empty() )
				pilha.pop();
			while(i < n){
				can = false;
				if(!pilha.empty()){
					if(pilha.top() == a[i]) {pilha.pop(); i++; can = true;}
				}
				if(j < n){
					if(!can && a[i] == tmp[j]) {i++;j++;}
					else if(!can) {pilha.push(tmp[j]); j++;}
					can = true;
				}
				if(!can) break;
			}
	
		if(pilha.empty())printf("Yes\n");
		else printf("No\n");

	}	
}
	printf("\n");
	return 0;
}
