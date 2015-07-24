#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define MAX 100001

using namespace std;
 
int n,d;
string entrada;
vector<char> saida;
int x,y,k;
int maior,cont;

int main() {

    while(1){
        scanf("%d %d",&n,&d);
		        
        if(n == 0 && d == 0)
            break;

		cont = 0;
        cin >> entrada;
        saida.clear();

		for(int i = 0 ; i < n; i++){
			if(saida.empty())
				saida.push_back(entrada[i]);
			else {
				x = saida.back();
				y = entrada[i];
				k = n - (i+1);
				cont = 0;
				if (x < y){
					while(x < y && !saida.empty() && cont <= k && !(saida.size() < (n-d) && k < (n-d) - saida.size())){
						saida.pop_back();
						x = saida.back();
						cont++;
					}
					saida.push_back(y);
				}
				else if(saida.size() < n-d) saida.push_back(entrada[i]);	
			}
		}
		
		for(int i = 0 ; i < saida.size(); i++)
			printf("%c",saida[i]);
		printf("\n");
	}
   return 0;
}
