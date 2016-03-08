#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;
set<pii> aux[10];

int ans(set<pii> s) {

    for(int k = 0; k < 10; k++) {
        bool flag = true;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                if(aux[k].find(mp(i,j)) != aux[k].end() && s.find(mp(i,j)) == s.end()) flag = false;
                if(aux[k].find(mp(i,j)) == aux[k].end() && s.find(mp(i,j)) != s.end()) flag = false;
            }
        if(flag) return k;
    }
    return -1;
}

void solveS() {

    string s;
    cin >> s;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            if(aux[s[j] -'0'].find(mp(i,0)) == aux[s[j] - '0'].end())
                printf(".");
            else printf("*");
            if(aux[s[j] - '0'].find(mp(i,1)) == aux[s[j] - '0'].end())
                printf(".");
            else printf("*");

            if(j == n-1) printf("\n");
            else printf(" ");
        }
    }
}

void solveB() {

    set<pii> aux2[n];
    char c1, c2;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            scanf("\n%c %c", &c1, &c2);
            if(c1 == '*')
                aux2[j].insert(mp(i,0));
            if(c2 == '*')
                aux2[j].insert(mp(i,1));
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d", ans(aux2[i]));
    puts("");
}

int main() {
 
    aux[0].insert(mp(0,1));
    aux[0].insert(mp(1,0));
    aux[0].insert(mp(1,1));

    aux[1].insert(mp(0,0));
    
    aux[2].insert(mp(1,0));
    aux[2].insert(mp(0,0));

    aux[3].insert(mp(0,0));
    aux[3].insert(mp(0,1));

    aux[4].insert(mp(0,0));
    aux[4].insert(mp(0,1));
    aux[4].insert(mp(1,1));

    aux[5].insert(mp(0,0));
    aux[5].insert(mp(1,1));
    
    aux[6].insert(mp(0,0));
    aux[6].insert(mp(0,1));
    aux[6].insert(mp(1,0));

    aux[7].insert(mp(0,0));
    aux[7].insert(mp(0,1));
    aux[7].insert(mp(1,0));
    aux[7].insert(mp(1,1));
   
    aux[8].insert(mp(0,0));
    aux[8].insert(mp(1,1));
    aux[8].insert(mp(1,0));

    aux[9].insert(mp(0,1));
    aux[9].insert(mp(1,0));

    while(scanf("%d",&n) != EOF && n > 0){
        char opt;
        scanf("\n%c", &opt);
        if(opt == 'S') solveS();
        else solveB();
    }

	return 0; 
}
