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

#define MAX 111  
#define INF 1000000000

int n, m, x, y;

int unionSet[MAX], sizeSet[MAX];

void clearUnion() { for(int i = 0; i < MAX; i++) { unionSet[i] = i; sizeSet[i] = 1; } }
int getParent(int a) { return (a == unionSet[a]) ? a : unionSet[a] = getParent(unionSet[a]); }
bool isSameSet(int a, int b) { return getParent(a) == getParent(b); }
void connect(int a, int b) { if(!isSameSet(a,b)) { sizeSet[getParent(b)] += sizeSet[getParent(a)]; unionSet[getParent(a)] = getParent(b); } }
int sizeOf(int a) { return sizeSet[getParent(a)]; }

int main() {
 
    int cont = 1;
    while(scanf("%d %d", &n, &m) != EOF && n && m) {
        
        clearUnion();

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            connect(x,y);
        }

        printf("Teste %d\n%s\n\n", cont++, sizeOf(x) == n ? "normal" : "falha");
    }

	return 0; 
}
