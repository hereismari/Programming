#include <bits/stdc++.h>


/*
	Temos dois tipos de pedra fixas e não fixas e temos que fazer um caminho de ida
	e vinda (ou seja passamos no caminho 2 vezes) e queremos diminuir a distancia
	do salto de uma pedra para outra.

	A entrada já esta ordenada entao isso nos ajuda, pois se está ordenada supondo
	a situação em que todas as pedras fossem fixas qual seria a resposta?
	A resposta seria o max(dist[i] - dist[i-1], res), em que dist[i] - dist[i-1] é
	a distancia da pedra i da borda menos a distancia da pedra i-1 da borda ou seja
	a distancia entre elas.

	Porém como existem pedras nao fixas podemos voltar a esse caso mais simples
	da seguinte forma: se a pedra for não fixa colocamos 2 pedras com essa mesma distancia
	(uma para ida e outra para a vinda) se for não fixa colocamos apenas 1 pedra.

	Assim para diminuir o pulo basta pular sempre de 2 em 2 pedras... por que?
	Pois de tal forma garantimos que estamos dando o menor pulo possível cada vez.
	Uma vez utilizando as pedras pares e na outra usando as impares, pois se na ida,
	por exemplo, resolvemos fazer um salto menor isso implica na vinda.

*/

using namespace std;

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int> >

#define MAX 1000100

vector<int> v;

int main() {

    int n, m, d;
	char c;
	int x;

	scanf("%d", &n);

    for(int turn = 1; turn <= n; turn++) {

    	scanf("%d %d", &m, &d);

        v.clear();

        v.pb(0);

        for(int i = 0; i < m; i++) {
            scanf("\n%c-%d", &c, &x);
            v.pb(x);
            if(c == 'B') v.pb(x);
        }

        v.pb(d);

        int ans = 0;
        for(int i = 3; i < v.size(); i += 2)
            ans = max(ans, v[i]-v[i-2]);

        for(int i = 2; i < v.size(); i += 2)
            ans = max(ans, v[i]-v[i-2]);

        printf("Case %d: %d\n", turn, ans);
    }

}
