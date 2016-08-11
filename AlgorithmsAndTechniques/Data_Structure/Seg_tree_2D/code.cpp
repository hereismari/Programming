#include <bits/stdc++.h>

using namespace std;

const int N=1000;

int t[2*N][2*N];

int n, m;

#define zero INT_MIN
#define f(x,y) max(x,y) // change here
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
	return 0;
}
