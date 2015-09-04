#include <bits/stdc++.h>
#define MAX 3000
using namespace std;

int dist, inicio, fim;
int d[MAX], a[MAX], b[MAX];
int n;
int main() {

	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d",&d[i], &a[i], &b[i]);
        }

	bool can = true;
	cin >> dist >> inicio >> fim;
	for(int i = 0; i < n; i++) {
		int maxH = (d[i]*b[i]);
		int minH = (d[i]*a[i]);
		if(maxH < inicio*dist || minH > fim*dist) can = false;
		if(maxH < fim*dist) fim = maxH/dist;
		if(minH > inicio*dist) inicio = minH/dist;
		
	}

	printf("%c\n",can ? 'Y' : 'N');
	return 0;
}
