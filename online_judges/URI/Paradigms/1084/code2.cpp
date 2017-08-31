#include <bits/stdc++.h>

#define MAX 100001

using namespace std;
 
int n,d;
string entrada;
char answer[MAX];

int top, pos;
int cont;
int size;

int main() {

    while(1){
     
		scanf("%d %d", &n, &d);	        
        if(n == 0 && d == 0)  break;

        cin >> entrada;
		size = 0;
		for(int i = 0 ; i < n; i++){
			if(size == 0) answer[size++] = entrada[i];
			else {
				top = answer[size-1];
				pos = n - (i+1);
				cont = 0;
				if (top < entrada[i]) {
					while(top < entrada[i] && size != 0 && cont <= pos && !(size < (n-d) && pos < (n-d) - size)){
						top = answer[--size];
						cont++; 
					}
				
					answer[size++] = entrada[i];
				}
				else if(size < n-d) answer[size++] = entrada[i];	
			}
		}
	
		for(int i = 0; i < n-d; i++)
			printf("%c",answer[i]);
		printf("\n");
	}
   return 0;
}
