#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define MAX 1000
#define MASK 20
using namespace std;

int atk[MAX], def[MAX], hab[MAX];
int n, a, d, h;
int main() {
  	
    scanf("%d %d %d %d",&n, &a, &d, &h);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&atk[i], &def[i], &hab[i]);
   	}
    for(int mask = 0; mask != (1<<n); mask++){
		bitset<21> foo(mask);
		int sum_atk = 0, sum_hab = 0, sum_def = 0; 
		int cont = 0;
		for(int i = 0; i < n; i++){
			if(foo.test(i))
			{
				sum_atk += atk[i];
				sum_def += def[i];
				sum_hab += hab[i];
				cont += 1;
			}
		}
		if(cont <= 1) continue;
		if(sum_atk == a && sum_def == d && sum_hab == h) { printf("Y\n"); return 0;}
	}	

    printf("N\n");
    return 0;
}
