#include <bits/stdc++.h>

using namespace std;

#define MAX 110

int n, m, S_i, S_j, E_i, E_j;
char a[MAX][MAX];
int dir[5];

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

string s;

int search(int i, int j, int dir[5], int index=0) {
  if(i < 0 || i >= n || j < 0 || j >= m) return 0;
  if(a[i][j] == '#') return 0;
  if(a[i][j] == 'E') return 1;
  
  if(index >= s.size()) return 0;
  
  int x = s[index] - '0';
  if(dir[x] == UP) return search(i-1, j, dir, index+1);
  if(dir[x] == DOWN) return search(i+1, j, dir ,index+1);
  if(dir[x] == LEFT) return search(i, j-1, dir, index+1);
  if(dir[x] == RIGHT) return search(i, j+1, dir, index+1);
  
}


int main() {

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf(" %c", &a[i][j]);
      if(a[i][j] == 'S') { S_i = i; S_j = j; }
      if(a[i][j] == 'E') { E_i = i; E_j = j; }
    }
  }
  
  cin >> s;
  
  int ans = 0;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(i != j)
        for(int k = 0; k < 4; k++) {
          if(i != k && j != k)
            for(int l = 0; l < 4; l++) {
              if(i != l && j != l && k != l) {
                dir[i] = UP;
                dir[j] = DOWN;
                dir[k] = LEFT;
                dir[l] = RIGHT;
                ans += search(S_i, S_j, dir);
              } 
            }
        }
    }
  }
  
  printf("%d\n", ans);
  return 0;
}
