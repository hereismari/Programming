#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d",&n);

	set<string> ans;
	int freq[n];
	string s;

	for(int i = 0; i < n; i++){
		cin >> s;
		ans.insert(s);
	}

	memset(freq,0,sizeof freq);
	vector<int> post_ans;
	for(set<string>::iterator it = ans.begin(); it != ans.end(); it++){
		s = *it;
//		cout << s << '\n';
		int aux = 0;
		for(int j = 0; j < s.size(); j++) if(s[j] == 'S') {freq[j]++; aux++;}
		post_ans.push_back(aux);
	}

	bool flag = false;
	for(int i = 0; i < n; i++)
		if(freq[i] != 1) flag = true;

	sort(post_ans.begin(), post_ans.end());
	if(flag) printf("-1\n");
	else {
		printf("%d\n",post_ans.size()); 
		printf("%d", post_ans[post_ans.size()-1]);
		for(int i = post_ans.size()-2; i >= 0; i--) 
			printf(" %d", post_ans[i]); 
		printf("\n");}
	return 0;
}
