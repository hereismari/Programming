#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;
    while(cin >> str) {
        
        int aux[str.size() + 1];
        aux[0] = -1;
        
        int j = -1;
        for(int i = 1; i <= str.size(); i++) {
            while(j != -1 && str[i-1] != str[j]) j = aux[j];
            aux[i] = j + 1;
            j = aux[i];
        }

        for(int i = 0; i <= str.size(); i++) {
            printf("%d ", aux[i]);
        }

        printf("\n");

    }

    return 0;
}
