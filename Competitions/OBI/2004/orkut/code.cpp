#include <bits/stdc++.h>
#define MAX 40
#define pb push_back
#define qi queue<int>
#define mi map<string, int>
#define ms map<int, string>
#define vi vector<int>
#define WHITE 0
#define BLACK 1
#define GREY 2
using namespace std;

int n, m, grau[MAX], color[MAX];
mi mapa;
ms nome;
qi q, ans;
string s,s1;
vi adj[MAX];
vector<string> aux;
int size = 0;

void topoSort() {

    while(!q.empty()) {
	    
        size++;        
	    int top = q.front(); q.pop();
        color[top] = GREY;
	    ans.push(top);

        for(int i = 0; i < adj[top].size(); i++){
            int v = adj[top][i];
            grau[v]--;
            if(grau[v] == 0) {q.push(v); color[v] = GREY; }
        }
    }
}

int main() {

    int teste = 1;
    while(scanf("%d",&n) == 1 && n > 0) {

        mapa.clear();
        nome.clear();
    	aux.clear();
        
        for(int i = 1; i < MAX; i++) adj[i].clear();
        
        memset(grau, 0, sizeof grau);
	    memset(color,WHITE, sizeof color);
        
        int cont = 1;
	    size = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            nome[cont] = s;
            mapa[s] = cont++;
	        aux.push_back(s);
        }

        for(int i = 0; i < n; i++){
            cin >> s >> m;
            grau[mapa[s]] = m;
            for(int j = 0; j < m; j++){
                cin >> s1;
                adj[mapa[s1]].pb(mapa[s]);
            }
        }
	
        sort(aux.begin(), aux.end());
	    for(int i = 0; i < n; i++) 
            if(grau[mapa[aux[i]]] == 0) q.push(mapa[aux[i]]);
        
        topoSort();
        printf("Teste %d\n",teste++);
	    
        if(size != n) printf("impossivel");
        else {
            if(!ans.empty()) { cout << nome[ans.front()]; ans.pop(); }
            while(!ans.empty()) {
                cout << " " + nome[ans.front()]; ans.pop();
            }
        }
        
        while(!ans.empty()) ans.pop();

        printf("\n\n");
    }

    return 0;
}
