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


int main() {

    int s[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int n = 15;

    int keep = 0;
    int cont = 0, j = 0;
    for(int i = 0; i < n; i++) {

        printf("%d\n", s[i]);
        fflush(stdout);
    
        char response[5];
        scanf("%s", response);
        if (strcmp(response, "yes") == 0) { cont += 1; keep = s[i]; j = i; }
    }

    if(cont == 1) {
        while(true) { 
            keep *= s[j];
            if(keep >= 100) break;
            printf("%d\n", keep);
            fflush(stdout);
            char response[5];
            scanf("%s", response);
            if (strcmp(response, "yes") == 0) cont += 1;
        }
    }

    printf("%s\n", cont >= 2 ? "composite" : "prime");
    fflush(stdout);

	return 0; 
}
