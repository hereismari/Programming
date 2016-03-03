#include <stdio.h>

using namespace std;

bool c = true;
bool d = true;

int entrada[5];
int tmp;
int main(){

	for(int i = 0 ; i < 5 ; i++)
		scanf("%d",&entrada[i]);
	
	tmp = entrada[0];
	for(int i = 1 ; i < 5 ; i++)
	{
		if(entrada[i] > tmp)
			d = false;
		if(entrada[i] < tmp)
			c = false;

		tmp = entrada[i];
	}	

	if(c)
	printf("C\n");
	else if(d)
	printf("D\n");
	else
	printf("N\n");

	return 0;
}
