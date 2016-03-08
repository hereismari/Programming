#include <bits/stdc++.h>
#define MAX 35

using namespace std;

int fa[MAX], fb[MAX], fc[MAX];

int main(){

    string a, b, c;
    int ab, ac, max_b, max_c;

    cin >> a >> b >> c;

    for(int i = 0; i < a.size(); i++) fa[a[i] - 'a']++;
    for(int i = 0; i < b.size(); i++) fb[b[i] - 'a']++;
    for(int i = 0; i < c.size(); i++) fc[c[i] - 'a']++;

    ab = INT_MAX;

    for(int i = 0; i < 26; i++)
        if(fb[i]) ab = min(ab, fa[i] / fb[i]);

    max_b = max_c = 0;
    for(int i = 0; i <= ab; i++){

        ac = INT_MAX;

        for(int j = 0; j < 26; j++)
            if(fc[j])
                ac = min(ac, (fa[j] - fb[j] * i) / fc[j]);

        if(max_b + max_c < i + ac){
            max_b = i;
            max_c = ac;
        }
    }   

    for(int i = 0; i < max_b; i++)
        cout << b;

    for(int i = 0; i < max_c; i++)
        cout << c;

    for(int i = 0; i < 26; i++){
        int aux = fa[i] - fb[i] * max_b - fc[i] * max_c;
        
        for(int j = 0; j < aux; j++){
            cout << char(i + 'a');
        }
    }
    
	return 0;
}
