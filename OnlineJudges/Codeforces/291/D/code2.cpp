#include <bits/stdc++.h>
#define ALPHA 3
#define MAX 100000
using namespace std;

int n, m;

struct Trie {

	struct Trie* child[3];
	bool leaf;
	bool setUp;
	int getnum(char c) { return c - 'a';}
	Trie();
	Trie(bool create) {setUp = true; for(int i = 0; i < ALPHA; i++) child[i]->setUp = false; leaf = false; }

	void insert(string s, int pos) {
		if (pos == s.length()) { leaf = true; return; }
		if (!child[getnum(s[pos])]->setUp) child[getnum(s[pos])] = new Trie(true);
		child[getnum(s[pos])]->insert(s, pos + 1);
	}

	bool check(string s, int pos, bool changed) {
		if (pos == s.length()) return leaf && changed;
		int num = getnum(s[pos]);
		bool ans = false;
		for (int i = 0; i < 3; ++i) 
		if (!child[i]->setUp && (!changed || num == i)) {
		ans |= child[i]->check(s, pos + 1, changed || (num != i));
    }
    return ans;
  }
};

int main() {

	Trie t;
	scanf("%d %d",&n,&m);
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		t.insert(s,0);
	}

	for(int i = 0; i < m; i++){
		cin >> s;
		printf("%s",t.check(s,0,false)?"YES\n": "NO\n");
	}

	return 0; 
}
