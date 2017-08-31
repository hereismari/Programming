#include <bits/stdc++.h>

using namespace std;

bool check(set<int> a[], int index, int b[], int n) {
   
    set<pair<int, int> > aux;
    
    int cont = index;
    for(int i = 1; i <= n; i++) {
        if(*(--a[i].upper_bound(index)) > index) return false;
    	aux.insert(make_pair(*(--a[i].upper_bound(index)), i));
    }

    for(set<pair<int, int> >::iterator it = aux.begin(); it != aux.end(); it++) {
        cont -= (b[it->second] + 1);
    }
    return cont >= 0;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int x, a[n+1];
    vector<int> v;
    set<int> s[n+1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(x > 0) {
            s[x].insert(i+1);
            v.push_back(i+1);
        }
    }

    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);

	for(int i = 1; i <= m; i++)
		if(s[i].size() == 0) {
			printf("-1\n");
			return 0;
		}

    // binary search
    int b = 0, e = v.size() - 1;
    int answer = -1;
    while(b <= e) {
        int mi = b + (e-b)/2;
        if(check(s, v[mi], a, m)) {
            answer = v[mi];
            e = mi - 1;
        }
        else {
            b = mi + 1;
        }
    }

    printf("%d\n", answer);

    return 0;
}
