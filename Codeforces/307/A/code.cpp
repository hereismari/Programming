#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	scanf("%d",&n);
	int x;

	int lista[n];
	int answer[n];

	for(int i = 0 ; i < n; i++)
		scanf("%d",&lista[i]);

	for(int i = 0; i < n; i++){
		answer[i] = 1;
		for(int j = 0; j < n; j++){
			if(lista[j] > lista[i])
				answer[i]++;
		}
	}	

	for(int i = 0 ; i < n ; i++)
		printf("%d ",answer[i]);

	return 0;
}
