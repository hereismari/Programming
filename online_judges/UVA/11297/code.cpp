#include <bits/stdc++.h>

using namespace std;

const int N=1000;

int t[2*N][2*N];
int n;

#define zero INT_MIN
#define f(x,y) max(x,y)
#define apply(x,y) x = y

int query(int x1, int y1, int x2, int y2) {
    x1 += n;
    x2 += n;
    y1 += n;
    y2 += n;
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
    y += n;
    apply(t[x][y], value);
    for (int tx = x; tx > 0; tx >>= 1)
      for (int ty = y; ty > 0; ty >>= 1) {
        if (tx > 1) t[tx >> 1][ty] = f(t[tx][ty], t[tx ^ 1][ty]);
        if (ty > 1) t[tx][ty >> 1] = f(t[tx][ty], t[tx][ty ^ 1]);
      }
}

int t2[2*N][2*N];
#define inf 40000 + 2
#define f2(x,y) min(x,y)

int query2(int x1, int y1, int x2, int y2) {
    x1 += n;
    x2 += n;
    y1 += n;
    y2 += n;
    int res = inf;
    for (int lx = x1, rx = x2; lx <= rx; lx = (lx + 1) >> 1, rx = (rx - 1) >> 1)
      for (int ly = y1, ry = y2; ly <= ry; ly = (ly + 1) >> 1, ry = (ry - 1) >> 1) {
        if ((lx & 1) != 0 && (ly & 1) != 0) res = f2(res, t2[lx][ly]);
        if ((lx & 1) != 0 && (ry & 1) == 0) res = f2(res, t2[lx][ry]);
        if ((rx & 1) == 0 && (ly & 1) != 0) res = f2(res, t2[rx][ly]);
        if ((rx & 1) == 0 && (ry & 1) == 0) res = f2(res, t2[rx][ry]);
      }
    return res;
}

void upd2(int x, int y, int value) {
    x += n;
    y += n;
    apply(t2[x][y], value);
    for (int tx = x; tx > 0; tx >>= 1)
      for (int ty = y; ty > 0; ty >>= 1) {
        if (tx > 1) t2[tx >> 1][ty] = f2(t2[tx][ty], t2[tx ^ 1][ty]);
        if (ty > 1) t2[tx][ty >> 1] = f2(t2[tx][ty], t2[tx][ty ^ 1]);
      }
}

int main() {
	
	int m;
	int x, x1, x2, y1, y2;
	char c;
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) t2[i][j] = inf;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			scanf("%d", &x);
			upd(i, j, x);
			upd2(i, j, x);
		}
			
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++) {
		scanf("\n%c", &c);
		
		if(c == 'q') {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d %d\n", query(x1, y1, x2, y2), query2(x1, y1, x2, y2));
		}
		else {
			scanf("%d %d %d", &x1, &y1, &x);
			upd(x1, y1, x);
			upd2(x1, y1, x);
		}
		
	}
	return 0;
}
