#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d",&n);
	int a[3*n];
	int answer = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		answer += a[i];
	}

	int maior_int_neg = 0;
	int aux1 = 0, aux2 = 0;
	int answer2 = 0;
	for(int i = 0; i < n; i++){
		aux1 += a[i];
		aux2 += a[i];
		if(aux1 > 0) {aux1 = 0;}
		maior_int_neg  = max(maior_int_neg,abs(aux1));
		if(aux2 < 0) aux2 = 0;
		answer2 = max(aux2,answer2);
	}

	printf("%d\n",max(answer2,answer + maior_int_neg));
	return 0;
}
