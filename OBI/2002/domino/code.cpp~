#include <bits/stdc++.h>
#define LINHAS 7
#define COLUNAS 8
using namespace std;

int mat[LINHAS][COLUNAS];
bool used[LINHAS][COLUNAS];
bool visited[30];
int ans, n, teste;

int peca(int i, int j, int i_aux, int j_aux) {
    int part1 = min(mat[i][j], mat[i_aux][j_aux]);
    int part2 = max(mat[i][j], mat[i_aux][j_aux]);
    int p = 0;
    if(part1 == 0) p = 1 + part2;
    if(part1 == 1) p = 7 + part2;
    if(part1 == 2) p = 12 + part2;
    if(part1 == 3) p = 16 + part2;
    if(part1 == 4) p = 19 + part2;
    if(part1 == 5) p = 21 + part2;
    if(part1 == 6) p = 22 + part2;
    return p;
}

void resolve(int i, int j) {
    while(used[i][j] && i < LINHAS){
        if(j >= LINHAS){
            i++;
            j = 0;
        }
        else j++;
    }

    if(i == LINHAS) ans++;
    else {
        for(int aux = 0; aux < 2; aux++) {
            int i_aux = (aux == 0 ? i : i + 1);
            int j_aux = (aux == 0 ? j + 1 : j);
            if(i_aux < LINHAS && j_aux < COLUNAS){
                int p = peca(i,j,i_aux,j_aux);
                if(!used[i_aux][j_aux] && !visited[p]){
                        used[i][j] = used[i_aux][j_aux] = true;
                        visited[p] = true;
                        resolve(i,j);
                        visited[p] = false;
                        used[i][j] = used[i_aux][j_aux] = false;
                }
            }
         }
    }
}

int main() {

    teste = 1;
    scanf("%d",&n);
    for(int k = 0; k < n; k++) {

        for(int i = 0; i < LINHAS; i++)
            for(int j = 0; j < COLUNAS; j++)
                scanf("%d",&mat[i][j]);

        memset(used, false, sizeof used);
        memset(visited, false,sizeof visited);
        ans = 0;

        resolve(0,0);

        printf("Teste %d\n%d\n\n",teste++,ans);
    }
    return 0;
}
