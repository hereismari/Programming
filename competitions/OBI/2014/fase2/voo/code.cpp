#include <stdio.h>
#include <math.h>

using namespace std;

bool verifica(int d1 ,int d2){
	
	int fuso = (d1-d2)/2;
	
	if(fuso > 12*60 || fuso <= -12*60) return false;
	if(d1 - fuso <= 0) return false;
	if(d2 + fuso <= 0) return false;
	if(d1 - fuso == d2 + fuso) return true;
	else return false;
}


int main(){
	
	int hora_minuto[8];

	double h1,h2,h3,h4;
	double d1,d2;

	for(int i = 0 ; i < 8 ; i+=2)
		scanf("%d:%d",&hora_minuto[i],&hora_minuto[i+1]);

	h1 = hora_minuto[0]*60 + hora_minuto[1];
	h2 = hora_minuto[2]*60 + hora_minuto[3];
	h3 = hora_minuto[4]*60 + hora_minuto[5];
	h4 = hora_minuto[6]*60 + hora_minuto[7];
	//printf("%f %f %f %f\n",h1,h2,h3,h4);

	d1 = h2 - h1;
	d2 = h4 - h3;
	
	if (verifica(d1,d2));
	else if (verifica(d1+(24*60),d2))
		d1 += (24*60);
	else if (verifica(d1-(24*60),d2))
		d1 -= (24*60);
	else if (verifica(d1,d2 - (24*60)))
		d2 -= (24*60);
	else if (verifica(d1-(24*60),d2 -(24*60))){
		d1 -= (24*60);
		d2 -= (24*60);
	}
	else if (verifica(d1,d2+(24*60)))
		d2 += (24*60);
	else if(verifica(d1+(24*60),d2+(24*60))){
		d1 += (24*60);
		d2 += (24*60);
	}
		
	int fuso = (d1-d2)/2;
	int tempo = (d1 - fuso);
	
	printf("%d %d\n", tempo, fuso/60);

	return 0;
}
