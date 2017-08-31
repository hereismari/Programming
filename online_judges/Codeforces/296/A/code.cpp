#include <stdio.h>
#include <iostream>

using namespace std;

long long int a,b,s;
long long int tmp;
int main(){
	
	scanf("%lld %lld",&a,&b);
	while(1){
//		printf("%lld %lld\n",a,b);
		if( a % b == 0)
			{
				s += a/b;
				break;
			
			}	
		s += (a/b);
		a -= (a/b)*b;
	
		
		if(a < b){
			tmp = a;
			a = b;
			b = tmp;
		}
	}		
	printf("%lld\n",s);
	return 0;
}
