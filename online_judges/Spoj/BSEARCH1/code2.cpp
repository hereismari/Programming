#include <stdio.h>
#define MAX 100001

using namespace std;

int a[MAX];
int n,q;
int x;

int bsearch(int num){

    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==num)
        {
            ans=mid;
            high=mid-1;
        }
        else if(a[mid]>num)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int main(){

	scanf("%d %d",&n,&q);
	for(int i = 0 ; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0 ; i < q ; i++)
	{
		scanf("%d",&x);
		printf("%d\n",bsearch(x));
	}


	return 0;
}
