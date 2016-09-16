#include <bits/stdc++.h>
#define MAX_1 11
#define MAX_2 6
int m, n, senha[MAX_2][2];
bool ans[MAX_2][MAX_1];
char c;



int main() {

  int teste = 1;
  while (scanf("%d", &n) == 1 && n > 0) {
      memset(ans, true, sizeof ans);
      for(int j = 0; j < n; j++) {
	for(int i = 0; i < 5; i++) scanf("%d %d",&senha[i][0], &senha[i][1]);
     	for(int i = 0; i < 6; i++) {
		scanf(" %c ",&c);
		for(int k = 0; k < MAX_1; k++){
			if(!ans[i][k] || (k != senha[c-'A'][0] && k != senha[c-'A'][1]))
				ans[i][k] = false; 
		}
	} 
     }

    printf("Teste %d\n", teste++);
    for(int i = 0; i < MAX_2; i++) 
	for(int k = 0; k < MAX_1-1; k++)
		if(ans[i][k]) printf("%d ",k);
    printf("\n\n");
  }

  return 0;
}
