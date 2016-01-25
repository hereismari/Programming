#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

struct horario{
	int inicio;
	int termino;
};

bool comp(horario h1, horario h2) {
	if(h1.inicio != h2.inicio)
		return h1.inicio < h2.inicio;
	
	return h1.termino - h1.inicio < h2.termino - h2.inicio;
}

int main()
{
	int n;
	struct horario horarios[MAX];

	scanf("%d",&n);
	for(int i = 0; i < n; i++)
   		scanf("%d %d",&horarios[i].inicio,&horarios[i].termino);

	sort(horarios, horarios + n, comp);
	int answer = 1;
	int fim = horarios[0].termino;
	for(int i = 1; i < n; i++){
	
		if(horarios[i].termino <= fim){ fim = horarios[i].termino; }	
		if(horarios[i].inicio >= fim) {answer += 1; fim = horarios[i].termino; }
		
	}
	
	printf("%d\n", answer);
	return 0;
}

