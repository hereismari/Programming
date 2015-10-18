#include <bits/stdc++.h> 

#define MAX 600
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

#define f(x, y) x.valid ? x : y 
#define zero T()
#define apply(x,y) x = y

using namespace std; 

struct T {
	int i, j;
	bool valid;
	T(int i2 = -1, int j2 = -1, bool v = false) {
		i = i2; j = j2; valid = v;
	}
};

struct Aux {
	
	int i, j, dist;
	Aux(int i2 = -1, int j2 = -1, int d = -1) {
		i = i2; j = j2; dist = d;
	}
	
	bool operator < (const Aux &a) const {
		return dist > a.dist;
	}
};


T t[2*MAX][2*MAX];

int n, m, r, c;
int cost[MAX][MAX], row[MAX][MAX], col[MAX][MAX], x[MAX], y[MAX];

// SEG FUCKING TREE 2D
T query(int x1, int y1, int x2, int y2) {
    x1 += r;
    x2 += r;
    y1 += c;
    y2 += c;
    T res = zero;
    for (int lx = x1, rx = x2; lx <= rx; lx = (lx + 1) >> 1, rx = (rx - 1) >> 1)
      for (int ly = y1, ry = y2; ly <= ry; ly = (ly + 1) >> 1, ry = (ry - 1) >> 1) {
        if ((lx & 1) != 0 && (ly & 1) != 0) res = f(res, t[lx][ly]);
        if ((lx & 1) != 0 && (ry & 1) == 0) res = f(res, t[lx][ry]);
        if ((rx & 1) == 0 && (ly & 1) != 0) res = f(res, t[rx][ly]);
        if ((rx & 1) == 0 && (ry & 1) == 0) res = f(res, t[rx][ry]);
      }
    return res;
}

void upd(int x, int y, T value) {
    x += r;
    y += c;
    apply(t[x][y], value);
    for (int tx = x; tx > 0; tx >>= 1)
      for (int ty = y; ty > 0; ty >>= 1) {
        if (tx > 1) t[tx >> 1][ty] = f(t[tx][ty], t[tx ^ 1][ty]);
        if (ty > 1) t[tx][ty >> 1] = f(t[tx][ty], t[tx][ty ^ 1]);
      }
}

void dijkstra(int begin, int end) {

    priority_queue<Aux> pq;
    int x_b = x[begin], y_b = y[begin];
    int x_e = x[end], y_e = y[end];
    pq.push(Aux(x_b, y_b, cost[x_b][y_b]));

    while(!pq.empty()) {
        
        int x_h = pq.top().i;
        int y_h = pq.top().j;
        int value = pq.top().dist;
        pq.pop();
        
        if(x_h == x_e && y_h == y_e) {
           	printf("%d", value - cost[x_h][y_h]);
           	return;
        }
        
        upd(x_h, y_h, false);
	int x1 = x_h -row[x_h][y_h] > 1 ? x_h -row[x_h][y_h] : 1;
	int y1 = y_h -col[x_h][y_h] > 1 ? y_h -col[x_h][y_h] : 1;
	int x2 = x_h + row[x_h][y_h] < r ? x_h + row[x_h][y_h] : r;
	int y2 = y_h + col[x_h][y_h] < c ? y_h + col[x_h][y_h]: c;
	
	while(true){
		T aux = query(x1, y1, x2, y2);
		if (!aux.valid) break;
		if(aux.i == x_e && aux.j == y_e) {
	   		printf("%d", value);
	   		return;
		}
		upd(aux.i, aux.j, false);
		pq.push(Aux(aux.i, aux.j, value + cost[aux.i][aux.j]));
	}
    }

    printf("%d", -1);
    return;
}


int main() {
 
    while(scanf("%d %d %d",&r, &c, &n) != EOF) {

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                scanf("%d", &cost[i][j]);
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                scanf("%d", &row[i][j]);
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                scanf("%d", &col[i][j]);
                
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        
        for(int i = 0; i < n-1; i++) {
        	for(int j = 1; j <= r; j++)
            	for(int k = 1; k <= c; k++)
            		upd(j, k, T(j, k, true));
            dijkstra(i, i+1);
            if(i != n-2) printf(" ");
        }
        puts("");
    }

	return 0; 
}
