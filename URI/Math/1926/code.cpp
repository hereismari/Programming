#include <bits/stdc++.h> 

#define MAX 1000100 
#define pb push_back
 
using namespace std; 

int n,m,x,y, twin[MAX];
bool prime[MAX];
vector<int> p;

void generatePrimes() {
    
    memset(prime, true, sizeof prime);
    memset(twin, 0, sizeof twin);
    
    prime[0] = prime[1] = false;

    for(int i = 2; i < MAX; i++)
        if(prime[i]) {
            for(int j = i+i; j < MAX; j+= i) prime[j] = false;
            p.pb(i);
       }

    for(int i = 0; i < p.size(); i++) 
       if(prime[p[i]-2] || prime[p[i]+2]) twin[p[i]] = true;

    for(int i = 1; i < MAX; i++) twin[i] += twin[i-1];
  
}

int main() {
 
    generatePrimes();
    scanf("%d" ,&n);
    while(n--) {
        scanf("%d %d", &x, &y);
        printf("%d\n", twin[y] - twin[x-1]);
    }

	return 0; 
}
