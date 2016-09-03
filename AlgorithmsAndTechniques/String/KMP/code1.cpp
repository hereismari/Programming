#include <bits/stdc++.h> 

#define MAX 101001 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

/*
 * C++ Program to Implement Knuth–Morris–Pratt Algorithm (KMP)
 */

int f[MAX];
int n, m;

void preKMP(string pattern) {

    int k;

    f[0] = 0; // this is always true
    for (int i = 1; i < m; i++) {

        k = f[i - 1]; // k is the length of the previous longest prefix/suffix
        bool match = false;
        do {
            if (pattern[k] == pattern[i]) { match = true; break; } // if match then it found the prefix/suffix 
            else if(k != 0) k = f[k-1]; // else keep looking in a smart way ;)!
        } while(k != 0);

        f[i] = (match) ? k + 1: 0; // if the prefix is != "" then the length is k+1.
    }
}
 
void kmp(string target, string pattern) {

    preKMP(pattern);     
    
    int i = 0, j = 0;        
    while (i < n) {
        if (target[i] == pattern[j]) {
            i++; j++;
            if (j == m) { printf("%d\n",i-m); j = f[j-1];}
        }
        else if (j == 0) i++;
        else j = f[j-1];
    }
}
 
int main(){

    scanf("%d %d", &n, &m);

    string s, w;
    cin >> s >> w;
    
    kmp(s, w);
    
    return 0;
}
