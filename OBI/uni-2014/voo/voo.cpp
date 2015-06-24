#include <stdio.h>
#include <math.h>

using namespace std;

int hora_minuto[8];

double h1,h2,h3,h4;

double c1;
double c2;
double d1,d2;

int main(){

	for(int i = 0 ; i < 8 ; i+=2)
		scanf("%0d:%0d",&hora_minuto[i],&hora_minuto[i+1]);

	h1 = hora_minuto[0] + hora_minuto[1]/60.0;
	h2 = hora_minuto[2] + hora_minuto[3]/60.0;
	h3 = hora_minuto[4] + hora_minuto[5]/60.0;
	h4 = hora_minuto[6] + hora_minuto[7]/60.0;
	//printf("%f %f %f %f\n",h1,h2,h3,h4);

	d1 = h2 - h1;
	d2 = h4 - h3;

	c1 = (d1 + d2) / 2.0;
	c2 = (d1 - d2) / 2;
	
//	printf("%d ",int(c2));
	
	c1 *= 60;	
	int cont = 0;
	while(c1 < 0){
		cont++;
		c1 += 12*60;
	}

	while (c2 <= -12) c2 += 24;
	while (c2 > 12) c2 -= 24;

	if (cont % 2 == 1){
		if (c2 > 0) c2 -= 12;
		else c2 += 12;
	}
	printf("%d %d\n", int(c1) , int(c2));

	return 0;
}



