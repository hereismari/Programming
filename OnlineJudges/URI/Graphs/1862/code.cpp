#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d",&n);

	char m[n][n];
	int color[n];	

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("\n%c",&m[i][j]);

	int c = 1;
	bool flag = false;
	vector<int> ans;
	memset(color, 0, sizeof color);
	for(int i = 0; i < n; i++){
		int aux = 0;
		if(color[i] == 0){
			for(int j = 0; j < n; j++){
				if(m[i][j] == 'S' && color[j] == 0) {color[j] = c; aux++;}
				else if(m[i][j] == 'S') flag = true;
				else if(m[i][j] == 'D' && color[j] == color[i]) flag = true;
			}
			ans.push_back(aux);
		}
		else {
			for(int j = 0; j < n; j++){
				if(m[i][j] == 'S' && color[j] != color[i]) flag = true;
				if(m[i][j] == 'D' && color[j] == color[i]) flag = true;
			}
		}
		c++;
	}

	if(flag) printf("-1");
	else {printf("%d\n",ans.size()); for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]); printf("\n");}
	return 0;
}
