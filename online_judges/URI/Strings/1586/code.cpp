#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll timeB, pontuacaoB, timeA, pontuacaoA;
vector<ll> pontuacoes;
vector<string> lista1;
int getAnswer(int n){

	for(int i = 0 ; i < n; i++){

		pontuacaoB -= timeB;
		timeB -= pontuacoes[i];

		timeA += pontuacoes[i];
		pontuacaoA += timeA;

		if(pontuacaoA == pontuacaoB) return i;
		if(pontuacaoA > pontuacaoB) return -1;

	}

	return -1;
}

int main(){
	string str;
	int n;
	while(1){

		scanf("%d",&n);
		if(n == 0) break;
		pontuacoes.clear(); lista1.clear();
		timeA = pontuacaoA = pontuacaoB = timeB = 0;
		for(int j = 1; j <= n ; j++){
		cin >> str;
		lista1.push_back(str);
		ll value = 0;
		for(int i = 0 ; i < str.size() ; i++)
			value += str[i];

		pontuacoes.push_back(value);
		timeB += value;
		pontuacaoB += value * j;
		
		}

		int answer = getAnswer(n);
		if(answer == -1) printf("Impossibilidade de empate.\n");
		else cout << lista1[answer] << "\n";
	
	}

	return 0;
}
