#include <stdio.h>

int main(){

    char oitavas[16] = "ABCDEFGHIJKLMNOP";
    char quartas[8], semi[4], fim[2];
    int time1, time2;

    for(int i = 0, j = 0; i < 16; i += 2, j++) {
        scanf("%d %d",&time1,&time2);
        if (time1 > time2)
            quartas[j] = oitavas[i];
        else
            quartas[j] = oitavas[i+1];
    }

    for(int i = 0, j = 0; i < 8; i += 2, j++){
        scanf("%d %d",&time1,&time2);
        if (time1 > time2)
            semi[j] = quartas[i];
        else
            semi[j] = quartas[i+1]; 
    }
    
	for(int i = 0, j = 0; i < 4; i += 2,j++){
        scanf("%d %d",&time1,&time2);
        if (time1 > time2)
            fim[j] = semi[i];
        else
            fim[j] = semi[i+1];
    }

    scanf("%d %d",&time1, &time2);
    if (time1 > time2)
        printf("%c",fim[0]);
    else
        printf("%c",fim[1]);

    return 0;
}
