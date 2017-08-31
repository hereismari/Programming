#include <bits/stdc++.h> 

#define MAX 200100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, ans[MAX];
char str[MAX];

int main() {
 
    scanf("%s", str);
    n = strlen(str);

    memset(ans, 0, sizeof ans);
    for(int i = 0, j = 0; i < n; i++) {
        if(i == 0) ans[j] = 1;
        else if(str[i] == str[i-1]) ans[j]++;
        else { j++; ans[j]++;}
    }

    int quant = 2;
    for(int i = 0, j = 0; i < n; j++) {
        if(i == 0) { 
            for(int k = 0; k < min(2,ans[i]); k++) 
                printf("%c", str[i]);
            if(ans[i] >= 2) quant = 1;
        }
        else if(ans[j-1] >= 2 && ans[j] >= 2) {
            for(int k = 0; k < quant; k++)
                printf("%c", str[i]);
            if(quant == 2) quant = 1;
            else if(quant == 1) quant = 2;
        }
        else if(ans[j] >= 2) {
            for(int k = 0; k < 2; k++) 
                printf("%c", str[i]);
            quant = 1;
        }
        else {
            printf("%c", str[i]);
            quant = 2;
        }
   
        if(i < n-1 && str[i+1] == str[i])
            while(i < n-1 && str[i+1] == str[i]) i++;
        i++;
    }

    puts("");
	return 0; 
}
