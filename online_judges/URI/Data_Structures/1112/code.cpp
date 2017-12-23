#include <bits/stdc++.h>

using namespace std;

const int N=1010;

int t[2*N][2*N];

int n, m;

#define zero 0
#define f(x,y) x + y // change here
#define apply(x,y) x+=y // change here

int query(int x1, int y1, int x2, int y2) {
    x1 += n;
    x2 += n;
    y1 += m;
    y2 += m;
    int res = zero;
    for (int lx = x1, rx = x2; lx <= rx; lx = (lx + 1) >> 1, rx = (rx - 1) >> 1)
      for (int ly = y1, ry = y2; ly <= ry; ly = (ly + 1) >> 1, ry = (ry - 1) >> 1) {
        if ((lx & 1) != 0 && (ly & 1) != 0) res = f(res, t[lx][ly]);
        if ((lx & 1) != 0 && (ry & 1) == 0) res = f(res, t[lx][ry]);
        if ((rx & 1) == 0 && (ly & 1) != 0) res = f(res, t[rx][ly]);
        if ((rx & 1) == 0 && (ry & 1) == 0) res = f(res, t[rx][ry]);
      }
    return res;
}

void upd(int x, int y, int value) {
    x += n;
    y += m;
    apply(t[x][y], value);
    for (int tx = x; tx > 0; tx >>= 1)
      for (int ty = y; ty > 0; ty >>= 1) {
        if (tx > 1) t[tx >> 1][ty] = f(t[tx][ty], t[tx ^ 1][ty]);
        if (ty > 1) t[tx][ty >> 1] = f(t[tx][ty], t[tx][ty ^ 1]);
      }
}

int main() {

  while(true) {
    int p;
    scanf("%d %d %d", &n, &m, &p);
    if(n == 0 && m == 0 && p == 0) break;
    //for(int i = 0; i < 2 * N; i++)
      //for(int j = 0; j < 2 * N; j++)
        //t[i][j] = 0;
    memset(t, 0, sizeof t);
    int x, y;
    int z, w, v;
    
    int q;
    scanf("%d", &q);
    char c;
    for(int i = 0; i < q; i++) {
      scanf(" %c", &c);
      if(c == 'A') {
        scanf("%d %d %d", &v, &x, &y);
        upd(x, y, v);
      }
      else {
        scanf("%d %d %d %d", &x, &y, &z, &w);
        int min_x_z = min(x, z), max_x_z = max(x, z);
        int min_y_w = min(y, w), max_y_w = max(y, w);
        x = min_x_z;
        y = min_y_w;
        z = max_x_z;
        w = max_y_w;
        printf("%d\n", query(x, y, z, w) * p);
      }
    }
    
    printf("\n");
  }

	return 0;
}
