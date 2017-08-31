#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

int n, m, x, y;

struct que {

    int size, a[100];
    int begin, last;

    que() {
        size = 0; begin = 0;
    }

    void add(int x) {
        a[size++] = x;
    }

    bool remove() {
        for(int i = begin; i < size; i++)
            if(a[i] < i-begin) { 
                last = a[i];
                for(int j = i; j >= 0; j--) {
                    a[j] = a[j-1];
                }
                begin++; 
                return true; 
            }
        return false;
    }

    int getLast() { return last; }
    int get(int i) { return a[i]; }

};

que q[100];

void solve() {

    while(q[0].remove()) {
        int last = q[0].getLast();
        for(int i = 1; i < n; i++)
            if(q[i].size <= last) { 
                q[i].add(last);
                break;
            }
    }
}

int main() {
 
    while(scanf("%d", &n) != EOF) {

        int a[n];
        
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);

        for(int i = 0; i < n; i++) q[0].add(a[i]);

        solve();

        int ans = 0;
        for(int i = 0; i < n; i++)
            if(q[i].size > 0) ans++;
            else break;

        printf("%d\n", ans);
    }

	return 0; 
}
