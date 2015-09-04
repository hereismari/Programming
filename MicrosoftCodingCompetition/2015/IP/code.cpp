#include <stdio.h>

using namespace std;

long long int ip1[4];
long long int ip2[4];
long long int ip3[4];

bool inValid;
bool outRange;

int main(){

	while(scanf("%lld.%lld.%lld.%lld %lld.%lld.%lld.%lld %lld.%lld.%lld.%lld",&ip1[0],&ip1[1],&ip1[2], &ip1[3], &ip2[0],&ip2[1],&ip2[2], &ip2[3], &ip3[0],&ip3[1],&ip3[2], &ip3[3]) != EOF){

	inValid = false;
	outRange = false;

	for(int i = 0 ; i < 4 ; i++)
		if(ip3[i] < 0 || ip3[i] > 255)
			inValid = true;
	
	for(int i = 0; i < 5 ; i++){
		if(ip1[i] != ip2[i] && ip3[i] < ip2[i] && ip3[i] > ip1[i])
			break;
		if(ip3[i] < ip1[i] || ip3[i] > ip2[i])
				outRange = true; 
			
	}
	
	if(inValid)
		printf("InValid\n");
	else if(outRange)
		printf("OutRange\n");
	else
		printf("InRange\n");

}
	return 0;
}
