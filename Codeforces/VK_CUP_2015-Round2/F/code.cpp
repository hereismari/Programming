#include <bits/stdc++.h>
#define BASE 5
#define ALPHA 30
#define MAX 200100

using namespace std;

int n, m;
vector<int> ans;
long long st[MAX], h1[ALPHA][MAX], h2[ALPHA][MAX];
int pos[MAX];
string s1, s2;

void buildHash(){
	for(char c = 'a'; c <= 'z'; c++) {
		int j = c-'a';
		for(int i = 0; i < n; i++)
			h1[j][i+1]=h1[j][i]*BASE + (s1[i] == c);
		for(int i = 0; i < m; i++)
			h2[j][i+1]=h2[j][i]*BASE + (s2[i] == c);
	}	
}

int main() {
	
	scanf("%d %d",&n,&m);
	cin >> s1 >> s2;
	
	buildHash();
	
	st[0] = 1;
	for(int i = 1; i < n; i++)
		st[i] = st[i-1] * BASE;
		

	for(int i = 0; i < 300; i++) pos[i] = -1;
	for(int i = 0; i < m;  i++) if (pos[s2[i]-'a'] == -1) pos[s2[i]-'a'] = i;
	
	for(int i = 0; i <= n-m; i++){
		bool flag = true;
		int d[ALPHA]; memset(d,-1,sizeof d);
		
		for(int j = 0 ; j < ALPHA; j++) {
			
			int x = pos[j]; if (x == -1) continue;
			int y = x+i; int k = s1[y] - 'a';
			
			if (d[j]!=-1 && d[j]!=k){flag = false;break;}
			if (d[k]!=-1 && d[k]!=j){flag = false;break;}
		
			d[j] = k; d[k] = j;
			if (h2[j][m] != h1[k][i+m]-h1[k][i]*st[m]){flag = false;break;}
		}
		
		if (flag)
			ans.push_back(i+1);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();++i)
		cout << ans[i] <<" ";
	cout << endl;
	return 0;
}

