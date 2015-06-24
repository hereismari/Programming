#include <bits/stdc++.h>
#define MAX 110

using namespace std;

int m[MAX][MAX];

bool goodCar(int x, int n){

	for(int i = 0 ; i < n; i++)
		if(m[i][x] == 2 || m[i][x] == 3) return false;
	for(int i = 0 ; i < n; i++)
		if(m[x][i] == 3 || m[x][i] == 1) return false;

	return true;
}

int main(){

	int n;
	scanf("%d",&n );
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j <  n; j++){
			scanf("%d",&m[i][j]);
		}

	vector<int> answer;
	for(int i = 0; i < n; i++)
		if(goodCar(i,n))
			answer.push_back(i+1);

	printf("%d\n",answer.size());
	for(int i = 0 ; i < answer.size(); i++)
		printf("%d ",answer[i]);
	if(answer.size() != 0) printf("\n");
	return 0;
}
