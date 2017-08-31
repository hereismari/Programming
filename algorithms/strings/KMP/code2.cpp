#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void kmp(string s, string t) {
    
    /* Prefix function */
    
    int prefix[t.size() + 1];
    prefix[0] = -1; // flag
    
    int k = prefix[0];
    for(int j = 1; j <= t.size(); j++) {
        while(k != -1 && t[k] != t[j-1]) k = prefix[k];
        prefix[j] = k + 1;
        k = prefix[j];
    }
    
    /* String Matching */
    int i = 0;
    int j = 0;

    while(j < s.size()) {
        if(i == -1) { i = 0; j++; }
        else if(t[i] == s[j]) {
            i++,j++;
            if(i == t.size()) { printf("%d\n", j - t.size()); i = prefix[i]; }
        }
        else i = prefix[i];
    }
 
}

int main() {
 
	int m;
	scanf("%d", &m);
    
    while(true) {
        
        string s, w;
        cin >> w >> s;
 
        kmp(s, w);
        if(scanf("%d", &m) == 1) cout << endl;
        else break;
    }
    
    return 0;
}
