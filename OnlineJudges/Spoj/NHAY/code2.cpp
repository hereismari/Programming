#include <bits/stdc++.h> 

using namespace std; 

/*
 * C++ Program to Implement Knuth–Morris–Pratt Algorithm (KMP)
 */

int n, m;

void preKMP(string pattern, int f[]) {

    int k;

    f[0] = 0; // this is always true
    for (int i = 1; i < m; i++) {

        k = f[i - 1]; // k is the length of the previous longest prefix/suffix
        bool match = false;
        do {
            if (pattern[k] == pattern[i]) { match = true; break; } // if match then it found the prefix/suffix 
            else k = f[k]; // else keep looking in a smart way ;)!
        } while(k != 0);

        f[i] = (match) ? k + 1: 0; // if the prefix is != "" then the length is k+1.
    }
}
 
void kmp(string target, string pattern, int f[]) {

    preKMP(pattern, f);     
    
    int i = 0, j = 0;        
    while (i < n) {
        if (target[i] == pattern[j]) {
            i++; j++;
            if (j == m) { printf("%d\n",i-m); j--; j = f[j];}
        }
        else if (j == 0) i++;
        else j = f[j];
    }
}
 
int main() {

    bool flag = false;
    scanf("%d", &m);
    while(true) {
        
        int f[m];

        string s, w;
        cin >> w >> s;

        n = s.size();
        kmp(s, w, f);
        if(scanf("%d", &m) == 1) cout << endl;
        else break;
    }
    
    return 0;
}
