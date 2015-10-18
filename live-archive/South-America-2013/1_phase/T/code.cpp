#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int ext1, ext2;
vi adj[MAX];
int dist[MAX];
int maior;
bool visited[MAX];

void findExt1(int i, int d){

	visited[i] = true;
	if(d > maior){
		maior = d;
		ext1 = i;
	}

	for(int j = 0; j < adj[i].size(); j++)
		if(!visited[adj[i][j]])
			findExt1(adj[i][j],d + 1);		
}

void findExt2(int i, int d) {

	visited[i] = true;
	if(d > maior){
		maior = d;
		ext2 = i;
	}

	for(int j = 0; j < adj[i].size(); j++)
		if(!visited[adj[i][j]])
			findExt2(adj[i][j],d + 1);		

}

void setDist(int i, int d) {

	visited[i] = true;
	dist[i] = max(d,dist[i]);
	for(int j = 0; j < adj[i].size(); j++)
		if(!visited[adj[i][j]])
			setDist(adj[i][j],d + 1);		
}

