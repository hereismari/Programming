#include <bits/stdc++.h>

using namespace std;

#define MAX_V 120
#define MAX_STRINGS 100

#define S second
#define F first

char emoticons[MAX_V][MAX_STRINGS];
char s[MAX_V][MAX_STRINGS];
set<pair<int, int> > edges;

int n, m;

bool equals(char s1[], int b, char s2[]) {

  for(int j = 0; j < strlen(s2); j++) {
    if(s1[b] == s2[j]) b++;
    else return false;
  }
  
 // printf("%s %d %s\n", s1, b, s2);
  
  return true;
}

void get_edges(char s1[], char s2[]) {

  int size_s1 = strlen(s1), size_s2 = strlen(s2);
  for(int i = size_s2-1; i < size_s1; i++) {
    int b = i - size_s2 + 1;
    if(equals(s1, b, s2)) {
     // printf("%d %d\n", b, i);
      edges.insert(make_pair(b, i));
    }
  }
}


int main() {
 
  while(scanf("%d %d", &n, &m) != EOF) {
  
    if(n == 0 && m == 0) break;
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) { 
      scanf("\n%s", emoticons[i]);
    }
    
    for(int i = 0; i < m; i++) {
      edges.clear();
      scanf("\n%[^\n]s", s[i]);
      for(int j = 0; j < n; j++) {
        get_edges(s[i], emoticons[j]);
      }
      
      int b = -1, e = -1;
      for(auto a : edges) {
        if (b == -1) { ans++; b = a.F; e = a.S; }
        else if (a.F > e) {
          b = a.F; e = a.S;
          ans++;
        }
        else {
          e = min(e, a.S);
        }
      //  printf("(%d, %d)\n", a.F, a.S);
      }
      
      //printf("%d\n", ans);
    }
    
    printf("%d\n", ans);
  }
     
  return 0;
}
