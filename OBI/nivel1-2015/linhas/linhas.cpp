#include <bits/stdc++.h>
#define MAX 700000

using namespace std;

int a[MAX];
int merge(int begin, int middle, int end){

	int aux[MAX];

	for(int i = begin; i <= end; i++)
		aux[i] = a[i];

	int i = begin;
	int j = middle + 1;
	int k = begin;
	int cont = 0;
	while(i <= middle && j <= end){
		if(aux[i] < aux[j])
			a[k++] = aux[i++];
		else{
			cont += middle - i + 1;
			a[k++] = aux[j++];
		}

	}
	
	while(i <= middle) a[k++] = aux[i++];
	while(j <= end) a[k++] = aux[j++];
	return cont;
}


int mergeSort(int begin, int end)
{
	int count = 0;
	if(begin < end){
	int middle = (begin+end)/2;
	count += mergeSort(begin, middle);
	count += mergeSort(middle + 1, end);
	count += merge(begin, middle, end);
	}
	return count;
}


int main() {

	int n;
	scanf("%d",&n);

	for(int i = 0 ; i < n; i++)
		scanf("%d",&a[i]);

	printf("%d\n", mergeSort(0,n-1));
	return 0;
}
