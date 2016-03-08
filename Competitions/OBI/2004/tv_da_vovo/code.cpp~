#include <bits/stdc++.h>
#define MAX 1001

int m, n, img[MAX][MAX];

int main() {

  int ic, jc, total_h, total_v, a, b, teste = 1;
  while (scanf("%d %d", &m, &n) == 2 && m > 0) {
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
	scanf("%d", &img[i][j]);

    total_h = total_v = 0;
    while(scanf("%d %d", &a, &b) == 2 && (a || b)) {
      total_h += a;
      total_v += b;
    }

    total_v = -total_v;

    printf("Teste %d\n", teste++);
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
	if (j != 0)
	  printf(" ");
	ic = (m + (i-total_v) % m) % m;
	jc = (n + (j-total_h) % n) % n;
	printf("%d", img[ic][jc]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
