#include <stdio.h>
#include <algorithm>

#define MAX1 1001
#define MAX2 10001

using namespace std;

int n,m;
int A[MAX1];
int B[MAX2];
int answer;
bool done = false;

int busca_binaria(int x){

	int begin = 0;
	int end = n;
	int middle = end/2;

	while(begin <= end){
		if(A[middle] < x)
			begin = middle + 1;
		else if (A[middle] > x)
			end = middle - 1;
		else
			return middle;
		middle = begin + (end - begin)/2;
	}

	return -1;
}

int busca_especial(int x, int j){

	int begin = 0;
	int end = j-1;

	while(begin <= end){
		if(B[end] + B[begin] < x)
			begin++;
		else if (B[end] + B[begin] > x)
			end--;
		else
			return 1;
	}

	return -1;
}

int main(){

	scanf("%d %d",&n, &m);

	for(int i = 0 ; i < n ; i++)
		scanf("%d",&A[i]);
	sort(A, A+n);

	for(int i = 0 ; i < m ; i++)
		scanf("%d",&B[i]);

	for(int i = 0 ; i < m ; i++){		
	if(busca_binaria(B[i]) == -1 && busca_especial(B[i],i) == -1 && !done){
			answer = B[i];
			done = true;
			break;
	}
	//selectionSort	
	for(int j = i -1; j >= 0; j--)
		if(B[j] > B[j+1])
		{
			int aux = B[j];
			B[j] = B[j+1];
			B[j+1] = aux;
		}

	}

	if (!done)
		printf("sim\n");
	else
		printf("%d\n",answer);

	return 0;
}
