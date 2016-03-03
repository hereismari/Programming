#include <bits/stdc++.h>
#define mp make_pair
#define p pair<int,int>
using namespace std;

bool comp(p a, p b){
	return a.second > b.second;
}

int main(){

	int n,m;
	scanf("%d %d",&n,&m);

	pair<int,int> a[m+1];
	for(int i = 1; i <= m; i++)
		a[i-1] = mp(i,i & -i);
	
	sort(a,a+m,comp);
	vector<int> answer;
	int sum = 0;
	for(int i = 0; i < m; i++){
		if(sum + a[i].second <= n){
			answer.push_back(a[i].first);
			sum += a[i].second;
		}
	}
	if(sum != n){ printf("-1"); return 0; }
	printf("%d\n",answer.size());
	for(int i = 0; i < answer.size(); i++)
		printf("%d ",answer[i]);

	return 0;
}
