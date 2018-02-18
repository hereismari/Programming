/*
  12526 - Cellphone Typing
  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3971
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000005

struct trie_node {
  bool is_leaf;
  int num_words;
  int next[26];
  trie_node() {
    this->is_leaf = false;
    for(int i = 0; i < 26; i++) this->next[i] = -1;
    this->num_words = 0;
  }
};


int aux;
trie_node trie[MAX];

void build_trie(string s, int i, int cur=0) {
  
  if(i < s.size()) {   
    
    int c = s[i] - 'a';
    
    if(trie[cur].next[c] == -1) {
      trie[cur].next[c] = ++aux;
    }
    
    int nxt = trie[cur].next[c];
    trie[nxt].num_words++;
    trie[nxt].is_leaf = (trie[nxt].is_leaf || (i == s.size()-1));
    
    build_trie(s, i+1, nxt);
  }
}

float res;
void dfs(int c, int cur, int r=1) {

  // printf("%c\n", 'a' + c);
  
  int cnt = 0;
  for(int i = 0; i < 26; i++) {
    if(trie[cur].next[i] != -1) cnt++;
  }

  for(int i = 0; i < 26; i++) {
    if(trie[cur].next[i] != -1) {
      int nxt = trie[cur].next[i];
      if(cnt == 1 && !trie[cur].is_leaf) {
        dfs(i, nxt, r);
      } else {
        dfs(i, nxt, r + 1);
      }
    }
  }
  
  if(trie[cur].is_leaf) {
    // printf("%d\n", r); 
    res += r;
  }
}

int main() {

  int n;
  while(scanf("%d", &n) != EOF) {
  
    aux = 1;
    res = 0.0;
    for(int i = 0; i < MAX; i++) trie[i] = trie_node();
    
    string s;
    for(int i = 0; i < n; i++) {
      cin >> s;
      build_trie(s, 0);
    }
    
    for(int i = 0; i < 26; i++) {
      if(trie[0].next[i] != -1) {
        dfs(i, trie[0].next[i]);
      }
    }
    printf("%.2lf\n", res / n);
  }

  return 0;
}
