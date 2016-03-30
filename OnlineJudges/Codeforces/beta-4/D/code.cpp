#include <bits/stdc++.h> 

using namespace std; 

#define MAX 5100 
#define pb push_back

struct envelope {
    int w, h, id;
    envelope(int w = 0, int h = 0, int id = 0) {
        this->w = w;
        this->h = h;
        this->id = id;
    }
    bool operator < (const envelope &o) {
        if(this->w < o.w) return true;
        if(this->h < o.h) return true;
        else return false;
    }
};

int n, w, h, x, y;
envelope v[MAX];

int dp[MAX];
int path[MAX];

bool valid(int w1, int w2, int h1, int h2) {
    return w1 > w2 && h1 > h2;
}

int solve() {
    
    for(int i = 0; i< n; i++) {dp[i] = -1; path[i] = -1; }
    for(int i = 0; i < n; i++) {
        if(valid(v[i].w, w, v[i].h, h)) { dp[i] = 1; path[i] = -1; }
        for(int j = 0; j < i; j++)
            if(valid(v[i].w, v[j].w, v[i].h, v[j].h) && dp[i] != -1 && dp[j] != -1 && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
    }
}

void printPath(int x) {

    vector<int> res;
    while(x != -1) {
        res.pb(v[x].id + 1);
        x = path[x];
    }
    for(int i = res.size() - 1; i >= 0; i--) 
        printf("%d ", res[i]);
}

int main() {
 
    while(scanf("%d %d %d", &n, &w, &h) != EOF){
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            v[i] = (envelope(x, y, i));
        }

        sort(v, v + n);
        solve();
        
        int answer = -1;
        int begin = -1;
        for(int i = 0; i < n; i++)
            if(dp[i] > answer) { answer = dp[i]; begin = i; }

        if(answer <= 0) printf("0\n");
        else {
            printf("%d\n", answer);
            printPath(begin);
        }
    }

	return 0; 
}
