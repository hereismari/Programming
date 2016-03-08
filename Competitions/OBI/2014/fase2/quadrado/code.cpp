#include <bits/stdc++.h>
#define MAX 50000
#define ll long long int
using namespace std;

ll line[MAX], col[MAX], M[MAX][MAX];

int main() {
  
  int n;
  scanf("%d",&n);

  memset(line, 0, sizeof line);
  memset(col, 0, sizeof col);

  for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) {
      scanf("%lld",&M[y][x]);
      line[y] += M[y][x];
      col[x] += M[y][x];
    }

  int cy = -1, cx = -1;

  for (int y = 0; y < n; y++)
    if (line[y] != line[(y+1) % n] && line[y] != line[(y+2) % n])
      cy = y;
  for (int x = 0; x < n; x++)
    if (col[x] != col[(x+1) % n] && col[x] != col[(x+2) % n])
      cx = x;


  ll newvalue = M[cy][cx];
  ll oldvalue = newvalue - (line[cy] - line[(cy+1)%n]);
  cout << oldvalue << " " << newvalue << endl;

  return 0;
}
