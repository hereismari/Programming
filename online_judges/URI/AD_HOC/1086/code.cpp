#include <stdio.h>
#include <stdlib.h> 
#define min(a,b) ((a < b) ? a : b)
#define MAX 100001
#define INF -1
#define ll long long int
ll  m,n;
ll cent;
ll k;
ll array[MAX];
  
int comp (const void * a, const void * b)
{
  return ( *(ll*)a - *(ll*)b );
}
  
ll gen(ll lado1, ll lado2, ll array2[MAX]){
  
    if((lado2*100) % cent != 0 ) return INF;
    ll quant = lado2*100/cent;
      
    int i = 0;
    int j = k-1;
    ll cont = 0;
//  prllf("\n%d\n",quant);
    ll x = 0;
    while(quant > 0 && j >= i){
          
        if(array2[j] > lado1) {j--; x = 1;}
        else if (array2[j] == lado1) {cont++; quant--; j--; x = 2;} 
        else {
			if(i == j)
				i++;
            else if(array2[i] + array2[j] > lado1){
                j--; x = 3;}
            else if(array2[i] + array2[j] < lado1){
                i++; x = 4;}
            else { cont+=2; quant--; i++; j--; x = 5;}  
  
        }
//      prllf("%d ",x);
  
    }
    if(quant>0) return INF;
    return cont;
}
  
int main(){
  
    while(1){
  
        scanf("%lld %lld",&n,&m);
        if(n == 0 && m == 0) break;
  
        scanf("%lld",&cent);
        scanf("%lld",&k);
        for(int i = 0; i < k ; i++) 
            scanf("%lld",&array[i]);
        qsort(array,k,sizeof(ll),comp);
        ll x1 = gen(n,m,array);
        ll x2 = gen(m,n,array);

        ll answer = min(x1,x2);

		if(x1 == -1) answer = x2;
		if(x2 == -1) answer = x1;

        if (answer != INF) printf("%lld\n",answer);
        else printf("impossivel\n");
    }
  
    return 0;
}
