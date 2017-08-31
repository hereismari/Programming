#include <bits/stdc++.h>
#define MAX 3000
using namespace std;

int dist, inicio, fim;
int d[MAX], a[MAX], b[MAX];
int n;
int main() {

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d",&d[i], &a[i], &b[i]);

	bool can = true;
	cin >> dist >> inicio >> fim;
	
    for(int i = 0; i < n; i++) {
		int maxH = (b[i] * dist); // divided by d[i]
		int minH = (a[i] * dist); // divided by d[i]
		if(maxH < inicio*d[i] || minH > fim*d[i]) can = false;
		if(maxH < fim*d[i]) fim = maxH/d[i];
		if(minH > inicio*d[i]) inicio = minH/d[i];
		
	}

	printf("%c\n",can ? 'Y' : 'N');
	return 0;
}
