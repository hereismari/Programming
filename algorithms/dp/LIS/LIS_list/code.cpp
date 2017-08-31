#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 1001

using namespace std;

int n;
int l[MAX];
vector < vector <int> > sets;
vector < int > x;
int res[MAX];
int dp(){

	int max = 0;
	memset(res,1,sizeof(res));
	int tmp_index = 0;	
	for(int i = 0 ; i < n ; i++)
		sets.push_back(x);

	for(int i = 0 ; i < n ; i++)
	{	
		res[i] = 1;
		tmp_index = i;
		sets[i].push_back(l[i]);
		for(int j = 0; j < i; j++)
			if(l[i] > l[j] && res[i] <= res[j]){
				res[i] = res[j] + 1;
				tmp_index = j;}
	if(tmp_index != i)	
		sets[i].insert(sets[i].begin(),sets[tmp_index].begin(),sets[tmp_index].end());
	}
	int index = 0;
	for(int i = 0; i < n ; i++)
		if(res[i] > max){
			max = res[i];
			index = i; }
	return index;
}

int main() {

	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++)
		scanf("%d",&l[i]);

	int index = dp();
	printf("%d\n",res[index]);
	for(int i = 0 ; i < sets[index].size(); i++)
		printf("%d ",sets[index][i]);
	
	printf("\n");
	return 0;
}
