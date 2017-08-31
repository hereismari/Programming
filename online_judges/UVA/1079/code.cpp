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

#define INF 1440*60
#define MAX 9

int n, id[MAX];
double a1[MAX], a2[MAX];

bool valid(double m) {
    
    double b = a1[id[0]];
    for(int i = 1; i < n; i++) {
        double aux = b + m;
        if(aux <= a2[id[i]]) b = max(aux, a1[id[i]]);
        else return false;
    }
    return (b - a2[id[n-1]]) <= 1e-3;
}

double bin_search() {
    
    double e = INF, b = 0, m;
    while(abs(b-e) >= 1e-3) {
        m = (b + e)/2.0;
        if(valid(m)) b = m;
        else e = m;
    }    
    return m;
}

int main() {
 
    int count = 1;
    while(scanf("%d", &n) != EOF) {

        if(n == 0) break;

        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &a1[i], &a2[i]);
            a1[i] = a1[i] * 60;
            a2[i] = a2[i] * 60;
            id[i] = i;
        }

        double ans = -1;
        do {
            ans = max(ans, bin_search());
        } while(next_permutation(id, id + n));

        ans = (int) (ans + 0.5);
        printf("Case %d: %d:%.02d\n", count++, (int)(ans/60), (int)(ans)%60);
    }

	return 0; 
}
