#include <bits/stdc++.h> 
#define MAX 500100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
#define ALPHA 3
 
using namespace std; 

int cont;
struct Node{
	int next;
	bool leaf, setUp;
	Node() {setUp = leaf = false;}
	Node(int next,bool leaf){
		this->next= next;
		this->leaf=leaf;
		setUp = true;
	}
};

int n,m,x,y;
Node tree[MAX][ALPHA];

void insertTree(int x, int index, string s){
	if(index >= s.length()) return;
	int c = s[index] - 'a';
	if(!tree[x][c].setUp)
		tree[x][c] = Node(++cont,index == s.length()-1);
	insertTree(tree[x][c].next,index + 1, s);
}

bool findInTree(int x, int index, string s, bool changed){
	int c = s[index] - 'a';
	if(index == s.length()-1){
		if(tree[x][c].setUp && changed) return tree[x][c].leaf;
		if(!tree[x][c].setUp && !changed) return tree[x][c].leaf;
		return false;
	}
	bool ans = false;		
	for(int i =0; i < ALPHA; i++)
		if(tree[x][i].setUp && (!changed || c == i)) {
			ans |= findInTree(tree[x][i].next,index+1,s, changed || (c!=i));
				return ans;
	}
}

int main() {

	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < ALPHA; j++)
				tree[i][j] = Node();
	
	cont = 0;
	scanf("%d %d",&n,&m);
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		insertTree(0,0,s);
	}

	for(int i = 0; i < m; i++){
		cin >> s;
		printf("%s",findInTree(0,0,s,false)?"YES\n": "NO\n");
	}

	return 0; 
}
