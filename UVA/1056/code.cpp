#include <bits/stdc++.h>
#define MAX 100
#define INF 10000001

using namespace std;

map<string,int> name_int;
int adj[MAX][MAX];

int floyd(int n){

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
	
	int answer = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			{
			answer = max(answer,adj[i][j]);}
	return answer;
}


int main(){

	int n,m;
	string name1, name2;
	int count = 1;
	while(1){
		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0) break;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n ; j++)
			{adj[i][j] = INF;}

		for(int i = 0,j = 1; i < m; i++){
			cin >> name1 >> name2;
			if(name_int.find(name1) == name_int.end())
				name_int[name1] = j++;	
			if(name_int.find(name2) == name_int.end())
				name_int[name2] = j++;
			adj[name_int[name1]][name_int[name2]] = 1;
			adj[name_int[name2]][name_int[name1]] = 1;
		}

		int answer = floyd(n);
		if(answer != INF)
			printf("Network %d: %d\n\n",count++,answer);
		else printf("Network %d: DISCONNECTED\n\n",count++);

	}

	return 0;
}
