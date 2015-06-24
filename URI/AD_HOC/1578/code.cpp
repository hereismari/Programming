#include <bits/stdc++.h>
#define ll long long int
#define MAX 110

using namespace std;

int main() {
	
	int t;
	ll x;
	int n;
	int cont = 4;
	ll m[MAX][MAX];
	ll space[MAX];
	scanf("%d",&t);
	while(t > 0){

		for(int i = 0 ; i < MAX; i++)
			for(int j = 0 ; j < MAX; j++){
				m[i][j] = 0;
				space[i] = 0;
			}
 
		scanf("%d",&n);
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%lld",&m[i][j]);
				m[i][j] *= m[i][j];	
				if(((int) log10(m[i][j]) + 1) > space[j])
				{
					space[j] = (int) log10(m[i][j]) + 1;
				}

			}	
		}
		printf("Quadrado da matriz #%d:\n",cont++);
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << setw(space[j]) << m[i][j];
				if(j < n -1)
					cout << " ";
			}	
			printf("\n");
		}
		t--;
	}

	return 0;
}
