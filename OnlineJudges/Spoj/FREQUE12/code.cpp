#include <bits/stdc++.h>
#define MAX 1000010

using namespace std;

int values[MAX] = {0};

int main() {

	int n;
	int x;
	scanf("%d",&n);
	int answer = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		values[x]++;
		if(values[x] == 1) answer++;
	}
	printf("%d\n",answer);

	return 0;
}
