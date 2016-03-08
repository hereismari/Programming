#include <bits/stdc++.h>
#define MAX 120
#define ll long long int

using namespace std;

char s[MAX];
int freq[MAX], n;
ll k, fat[MAX];

void calculateFat() {
    fat[0] = 1;
    for(int i = 1; i <= 16; i++)
        fat[i] = i*fat[i-1];
}

void buildFreq() {
    memset(freq,0,sizeof freq);
    for(int i = 0; i < n; i++) freq[s[i] - 'A']++;
}

ll getPos(int index, int cont) {
    ll ans = fat[n-cont];
    for(int i = 0; i < 30; i++)
        if(i == index) ans /= fat[freq[i]-1];
        else ans /= fat[freq[i]];
   // printf("%lld\n", ans);
    return ans;
}
void answer() {

    int cont = 0;
    ll aux = 0;
    while(cont < n) {
        for(int i = 0; i < 30; i++){
            aux += freq[i] > 0?getPos(i,cont+1): 0;
            if(freq[i] > 0 && aux >= k){
                k -= (aux - getPos(i,cont+1));
                printf("%c",i+'A');
                cont++;
                freq[i]--;
                aux = 0;
                break;
            }
        }
   }
}

int main() {

    calculateFat();

    while(true){
        scanf("%s %lld",s, &k);
        if(s[0] == '#' && k == 0) break;
        n = strlen(s);
        buildFreq();
        answer();
        printf("\n");
    }
    return 0;
}
