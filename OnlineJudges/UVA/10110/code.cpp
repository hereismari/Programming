#include <cmath>
#include <cstdio>

using namespace std;

bool div(long long int n){
	long long int root = sqrt(n);
	return (root * root) == n;
}

int main(){
	long long int n;
	while(1){
		scanf("%lld",&n);
		if(n == 0) break;
		printf("%s\n",div(n)?"yes":"no");}
	return 0;
}
