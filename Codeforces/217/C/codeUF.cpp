#include <stdio.h>
#include <vector>

#define MAX 1100

using namespace std;

int n;

vector<int> pset(MAX);
vector<int> sizeSet(MAX);
int x_pos[MAX];
int y_pos[MAX];

void init(int _size){for(int i = 0 ; i < _size; i++){ pset[i] = i; sizeSet[i] = 1;}}
int findSet(int i) { return (i == pset[i]) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { sizeSet[findSet(j)] += sizeSet[findSet(i)]; pset[findSet(i)]  = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
int sizeOfSet(int i) { return sizeSet[findSet(i)]; }

int numberofSets(int _size) { 
	int cont = 0; 
	for(int i = 0 ; i < _size; i++) 
		if (pset[i] == i){
			 cont++; 
//			 printf("%d ",i);
		} 
	
	return cont; 
}

int main(){

	scanf("%d",&n);
	init(n);	
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d %d",&x_pos[i],&y_pos[i]);
		for(int j = 0 ; j < i ; j++)
			if(x_pos[i] == x_pos[j] || y_pos[i] == y_pos[j]){
				unionSet(i,j);
				break; }
	}
	
	printf("%d\n",numberofSets(n) -1);
	return 0;
}
