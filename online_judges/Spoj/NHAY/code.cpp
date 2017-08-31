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
        while(true) {
            if (pattern[k] == pattern[i]) { match = true; break; } // if match then it found the prefix/suffix 
            if(k == 0) break;
            else k = f[k-1]; // else keep looking in a smart way ;)!
        }

        f[i] = (match) ? k + 1: 0; // if the prefix is != "" then the length is k+1.
    }
}
 
void kmp(string target, string pattern, int f[]) {

    preKMP(pattern, f);     

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
