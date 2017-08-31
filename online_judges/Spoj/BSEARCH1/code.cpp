#include <stdio.h>
#define MAX 100001

using namespace std;

int a[MAX], n, q, x;

int bsearch(int num) {

    int low = 0, high = n-1;
    
    while(low <= high) {
        
        int mid = (low + high)/2;
        
        if(a[mid] > num) high = mid - 1;
        else if(a[mid] < num) low = mid+1;
        else if(low != high) high = mid;
        else return mid;
    }

    return -1;
}

int main() {

	scanf("%d %d", &n, &q);

    for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
	
    for(int i = 0 ; i < q ; i++) {
		scanf("%d", &x);
		printf("%d\n", bsearch(x));
	}

	return 0;
}
