#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(){
	int n,m,x;
	scanf("%d %d",&n,&m);
	int array[MAX] = {false};
	for(int i = 0 ; i < m ;i++)
	{
		scanf("%d",&x);
		array[x] = true;
	}
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&x);
		if(array[x]) printf("0\n");
		else printf("1\n");
		array[x] = true;
	}


	return 0;
}
