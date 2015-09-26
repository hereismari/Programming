#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 120

using namespace std;

int l[MAX], c[MAX];
string matrix[MAX][MAX];
map<string, int> mapa;
set<string> st;
int n, m;

void attMatrix(string s){

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == s){
                l[i] -= mapa[s];
                c[j] -= mapa[s];    
            }
}

int main() {

        while(scanf("%d %d", &n, &m) != EOF) {

        mapa.clear();
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matrix[i][j];
                mapa[matrix[i][j]] = INF;
                st.insert(matrix[i][j]);
            }
            cin >> l[i];
        }

        for(int i = 0; i < m; i++)
            cin >> c[i];

        while(true){
            
            bool flag = false;
            for(int i = 0; i < n; i++){
                set<string> aux;
                int cont = 0;
                for(int j = 0; j < m; j++){
                    if(mapa[matrix[i][j]] == INF) {cont++; aux.insert(matrix[i][j]);}
                }
                if(aux.size() == 1) {
                    string s = *aux.begin();
                    //cout << s << '\n';
                    mapa[s] = l[i]/cont;
                    attMatrix(s);
                    l[i] = 0;
                    flag = true;
                    break;
                }
            }

            if(flag) continue;
            for(int j = 0; j < m; j++){
                set<string> aux;
                int cont = 0;
                for(int i = 0; i < n; i++){
                    if(mapa[matrix[i][j]] == INF) { cont++; aux.insert(matrix[i][j]);}
                }
                if(aux.size() == 1) {
                    string s = *aux.begin();
                    //cout << s << '\n';
                    mapa[s] = c[j]/cont;
                    attMatrix(s);
                    c[j] = 0;
                    flag = true;
                    break;
                }
            }

            if(!flag) break;

        }
       
        for(map<string, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
            cout << it->first << ' ' << it->second << endl ;
        }
    }

    return 0;
}

