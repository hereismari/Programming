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

#define MAX 1000100  
#define INF 1000000000

int n, m;
ll x, y;
char s[20], char_remove, char_insert;

priority_queue<ll> q;

struct operation {

    char op;
    int id;
    ll x;

    operation(char op, ll x, int id = 0) {
        this->op = op;
        this->x = x;
        this->id = id;
    }
};

vector<operation> v, aux;

void fix(int id, int a, bool f = false) {
    while(!q.empty() && -1*q.top() < a) {
        aux.pb(operation('r', -1, id));
        q.pop();
    }

    if(q.empty() || -1*q.top() != a) {
        if(f) q.push(-1*a);
        aux.pb(operation('i', a, id));
    }
}

int main() {
 
    while(scanf("%d", &n) != EOF) {
        
        for(int i = 0; i < n; i++) {
            scanf("\n%s", s);
            if(s[0] == 'r') x = -1;
            else scanf("%lld", &x);
            v.pb(operation(s[0], x));
        }

        for(int i = 0; i < n; i++) {
            if(v[i].op == 'i') q.push(-1*v[i].x);
            if(v[i].op == 'g' && !q.empty() && -1*q.top() == v[i].x) {
                continue;
            }
            if(v[i].op == 'r' && !q.empty()) {
                q.pop();
            }
            else if(v[i].op == 'g') {
                fix(i, v[i].x, true);
            }
            else if(v[i].op == 'r') {
                fix(i, 1);
            }
        }

        printf("%d\n", n + aux.size());
        for(int i = 0, j = 0; i < n;) {
            if(j < aux.size() && aux[j].id == i) {
                if(aux[j].op == 'r')
                    printf("%s\n", "removeMin");
                else    
                    printf("%s %lld\n", "insert", aux[j].x);
                j++;
            }
            else {
                if(v[i].op == 'r')
                    printf("%s\n", "removeMin");
                else if(v[i].op == 'i')
                    printf("%s %lld\n", "insert", v[i].x);
                else 
                    printf("%s %lld\n", "getMin", v[i].x);
                i++;
            }
        }
    }

	return 0; 
}
