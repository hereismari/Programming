#include <stdio.h>
#include <stack>

#define MAX 1000001

using namespace std;

stack<int> open;
int c[MAX];
int d[MAX];

char input[MAX];

int l,r; 
char ch;
int main(){

	int n = 0;
	int l,r;
	l = -1;
	r = 0;
	while(scanf("\n%c",&ch) != EOF){
		input[n] = ch;
		n++;
	}
	
	for(int i = 0 ; i < n ; i++){
		if(input[i] == '(') {open.push(i); continue;}
		
		if(open.empty()) {d[i] = -1; c[i] = -1;}
		else{
			int index = open.top();
			open.pop();
			d[i] = index;
			c[i] = d[i];
			if(input[d[i]-1] == ')' && c[d[i] -1] != -1) c[i] = c[d[i]-1];
			
			if(i - c[i] > l) {l = i - c[i]; r = 1;}
			else if(i - c[i] == l){r++;}	
	
		}

	}
	if(l == -1) printf("0 1\n");
	else printf("%d %d\n",l+1,r);
	return 0;
}
