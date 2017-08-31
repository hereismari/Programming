#include <stdio.h>

using namespace std;

int main(){


	int cow,car,door;
	double prob;

	while(scanf("%d %d %d",&cow,&car,&door) != EOF){
		double prob1 = ((double)cow/(car+cow))*((double)car/(car+cow-door-1));
		double prob2 = ((double)car/(car+cow))*((car-1)/((double)car+cow-door-1)); 
		prob =  prob1 + prob2;
		printf("%.5f\n",prob);

	}

	return 0;
}
