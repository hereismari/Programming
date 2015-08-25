#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m, k, x;
	scanf("%d %d",&n, &k);

	int answer = 0, size = 0;
	for(int i = 0; i < k; i++){
		scanf("%d",&m);
		int flag = 1;
		for(int j = 0; j < m; j++){
			scanf("%d",&x);
			if(flag == x) flag++;
		}
		if(flag > 1) {size = flag-1; answer += (m-(flag-1));}
		else answer += m-1;
	}

	answer += n-size;
	printf("%d\n",answer);
	return 0;
}
