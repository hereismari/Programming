#include <stdio.h>
#include <algorithm>

#define MAX_POT 31
#define MAX_LIST 36
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

using namespace std;

int t;
int n,k;
long long int list[MAX_LIST];
bool uti[MAX_LIST];
long long int res;

int main(){

	scanf("%d",&t);
	for(int i  = 0 ; i < t ;i++){
		scanf("%d %d",&n,&k);
		for(int j = 0 ; j < n; j++)
			scanf("%lld",&list[j]);
		
		for(int j = 0 ; j < MAX_LIST ; j++)
			uti[j] = true;
		
		res = 0; 		
		int cont = 0;
		for(int j = MAX_POT-1; j >= 0; j--)
		{	
			cont = 0;
			for(int p = n-1; p >= 0; p--)
			{	
				if(uti[p] && (CHECK_BIT(list[p],j))){
//					printf("%lld ",list[p]);
					cont++; 
					}
			}
			if(cont >= k)
			{
				res = 0;
//				printf("\n");
				for(int p = n-1; p >= 0; p--){
					if(!CHECK_BIT(list[p],j))
						uti[p] = false;
					else if (res == 0)
						res = list[p];
					else
						res = res & list[p];
				}
//				printf("%lld\n",res);
			}

		}
		printf("%lld\n\n",res);
	}
	return 0;
}
