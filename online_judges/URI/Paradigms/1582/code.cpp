#include <stdio.h>
#include <math.h>
using namespace std;

int a,b,c;
int l[3];
bool tpp;
bool tp;
int x;
int mdc(int m, int n){
	int r;
	while ((r = m % n) != 0){
		m = n;
		n = r;
	}
	return n;
}

void sort(int l[3]){
	int tmp;
	for(int i = 0; i < 3 ; i++)
		for(int j = i+1; j < 3; j++)
			if( l[j] > l[i] )
			{
				tmp = l[j];
				l[j] = l[i];
				l[i] = tmp;
			} 
}

int main(){

	while(scanf("%d %d %d", &l[0],&l[1],&l[2]) != EOF){
		sort(l);
		tp = tpp = false;
		a = l[0];
		b = l[1];
		c = l[2];

//		printf("%d %d %d\n",a,b,c);

		if (pow(a,2) == pow(b,2) + pow(c,2) || (pow(b,2) == pow(a,2) + pow(c,2)) || (pow(c,2) == pow(b,2) + pow(a,2)))
			tp = true;
		if(tp){
			x = mdc(a,b);
			if( (x > c ?mdc(x,c):mdc(c,x)) == 1)
				tpp = true;
		}

		if(tpp)
			printf("tripla pitagorica primitiva\n");
		else if(tp)
			printf("tripla pitagorica\n");
		else
			printf("tripla\n");
	}

	return 0;
}
