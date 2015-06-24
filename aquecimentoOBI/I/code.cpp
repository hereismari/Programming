#include <bits/stdc++.h>
#define MAX 100
#define INF -1
#define ll long long int
using namespace std;

vector<ll> livros[MAX];
vector<ll> answer;

bool comp(int a, int b) { return a > b; }

int main() {

	ll n, x;
	for(int i = 0 ; i < 5; i++){
		scanf("%lld",&n);
		for(int j = 0; j <  n; j++)
		{
			scanf("%lld",&x);
			livros[i].push_back(x);
		}
	}


	for(int i = 0 ; i < livros[0].size(); i++)	
		for(int j = 0 ; j < livros[1].size(); j++)	
			for(int k = 0 ; k < livros[2].size(); k++)	
				for(int l = 0 ; l < livros[3].size(); l++)	
					for(int m = 0 ; m < livros[4].size(); m++)	
						answer.push_back(livros[0][i] + livros[1][j] + livros[2][k] + livros[3][l] + livros[4][m]);

	sort(answer.begin(),answer.end(),comp);

	scanf("%d",&n);
	ll res = 0;
	for(int k = 0 ; k < n; k++)
		res += answer[k];

	printf("%lld\n",res);
	return 0;
}
