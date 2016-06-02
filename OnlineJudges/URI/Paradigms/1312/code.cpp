#include <bits/stdc++.h>

using namespace std;


/*
  O problema pode ser resolvido utilizando programação dinâmica (DP).
  Para ajudar a resolver o problema podemos ver a entrada como uma matriz do
  tipo triangular superior (http://www.mathematicsdictionary.com/spanish/vmd/images/t/triangularmatrix.gif).
  Tendo isto definido e sabendo que a DP guardará a resposta de fato,
  ou seja guardará o maior valor possível definido de acordo com o enunciado,
  podemos definir a dp da seguinte forma, tal que a é uma matriz com a soma acumulada
  das colunas:
    A dp dp[i][j] será calculada de baixo pra cima da seguinte forma:
      dp[i][j] = max(a[i][j], dp[i+1][j])
      # pois você pode remover um novo valor ou remover algum valor abaixo

    Antes disso no entanto atualizamos a matriz do somatorio da seguinte forma:
      	a[i][j] = dp[i-1][j-1] + a[i][j];
        # pois essa matriz guardará o valor que será conseguido ao remover a[i][j]
        assim, se removermos a[i][j] todas bolas acima deverão ser retiradas (a[i][j] atualmente)
        e todas a esquerda superior (dp[i][j] pois já tem quais os melhores valores das colunas a esquerda).
*/



#define ll long long
#define MAX 1010

#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>

int n;
ll a[MAX][MAX], dp[MAX][MAX];

ll solve() {

	ll res = 0LL;

	dp[n][1] = a[n][1];
	res = max(res, dp[n][1]);

	for(int i = n - 1; i >= 1; i--) {
		res = max(a[i][1], res);
		dp[i][1] = max(dp[i + 1][1], a[i][1]);
	}

	for(int j = 2; j <= n; j++){

		for (int i = j; i <= n; i++) {
			a[i][j] = dp[i-1][j-1] + a[i][j];
			res = max(res, a[i][j]);
		}
		dp[n][j] = a[n][j];

		for (int i = n - 1; i >= j; i--) dp[i][j] = max(dp[i+1][j], a[i][j]);
		dp[j-1][j] = max(dp[j][j], 0LL);
	}

	return res;
}

int main() {

	while(scanf("%d", &n) && n) {

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++) {
                scanf("%lld", &a[i][j]); a[i][j] += a[i - 1][j];
				        dp[i][j] = 0;
			}

        printf("%lld\n", solve());
    }
    return 0;
}
