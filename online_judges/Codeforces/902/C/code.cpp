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

#define MAX 300100  
#define INF 1000000000

int n, m, x, y;
int a[MAX];

int main() {
 
  while(scanf("%d", &n) != EOF) {
  
    bool ambiguos = false;
    int number = 0;
    for(int i = 0; i <= n; i++) {
      scanf("%d", &a[i]);
      number += a[i];
      if(i > 0 && a[i-1] >= 2 && a[i] >= 2) ambiguos = true;
    }
    
    if(!ambiguos) { 
      printf("perfect\n");
      continue;
    }
    else {
      printf("ambiguous\n");
    }
    
    int count = 0;
    for(int i = 0; i <= n; i++) {
      if(i == 0) {
        printf("0");
      }
      else if(a[i-1] >= 2 && a[i] >= 2) {
        printf(" %d", count - 1);
        for(int j = 0; j < a[i]-1; j++) printf(" %d", count);
      }
      else {
        for(int j = 0; j < a[i]; j++) printf(" %d", count);
      }
      count += a[i];
    }
    
    printf("\n");
    
    count = 0;
    for(int i = 0; i <= n; i++) {
      if(i == 0) {
        printf("0");
      }
      else {
        for(int j = 0; j < a[i]; j++) printf(" %d", count);
      }
      count += a[i];
    }
    
    
    printf("\n");
    
  }

	return 0; 
}
