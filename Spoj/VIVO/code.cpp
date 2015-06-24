#include <stdio.h>
#include <algorithm>
#define MAX 1000
using namespace std;

struct participante{
	int id;
	bool vivo;
};

participante cria_participante(int val){
	participante result;
	result.id = val;
	result.vivo = true;
	return result;
}

participante a[MAX];
int p,r;
int x;
int n,j;

int main(){
	int cont = 0;
	while(1){

		scanf("%d %d",&p,&r);
		if(p == 0 && r == 0) break;
		for(int i = 0 ; i < p ; i++){
			scanf("%d",&x);
			a[i] = cria_participante(x);
		}

		for(int i = 0 ; i < r; i++){
			scanf("%d %d",&n,&j);
			int l = 0;
			for(int k = 0 ; k < n ; k++){
				scanf("%d",&x);
				while(!a[l].vivo) l++;
				if(x != j) {a[l].vivo = false;}
				else l++;
			}

		}
		printf("Teste %d\n",++cont);
		for(int i = 0 ; i < p; i++)
			if(a[i].vivo) printf("%d\n",a[i].id);

	}

	return 0;
}
