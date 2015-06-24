#include <bits/stdc++.h>
#define MAX 1002
#define MAX_CHAR 30

using namespace std;

char n[MAX];
vector<int> adj[MAX]; // Lista de adjacencia
map<string,bool> visit;

void reset(){
	for(int i = 0 ; i < MAX; i++) adj[i].clear();
	visit.clear();
}

void dfs(int i, string str){
	string str1 = str;
	str1 += n[i];
	visit[str1] = true;
	cout << str1 << "\n";
	for(int j = 0; j < adj[i].size(); j++)
		if(!visit[str1+n[adj[i][j]]])
			dfs(adj[i][j],str1);
}

string str;

int main(){

	while(scanf("%s",n) != EOF){

		reset();

		for(int i = 0 ; i < strlen(n) ; i++)
			for(int j = i + 1 ; j < strlen(n) ; j++)
				adj[i].push_back(j);

		for(int i = 0 ; i < strlen(n); i++)	
				{str = ""; dfs(i,str);}

		 for (map<string,bool>:: iterator it=visit.begin(); it!=visit.end(); ++it)
			cout << it->first  << '\n';
		
		 printf("\n");
	}
	return 0;
}
