#include <bits/stdc++.h>

#define MAX 100011

using namespace std;

char s[MAX], fav_letters[30];

char ch[30], str_ans[30];
int value[30];

int ans;
int k, m, n;

int getValue() { 
    int v = 0; 
    for(int i = 0; i < k; i++) v += value[fav_letters[i]-'a'];
    return v;
}

void connect(char a, char b) {

    int pos_a, pos_b, aux;
    for(int j = 0; j < 26; j++) {
        if(ch[j] == a) pos_a = j;
        if(ch[j] == b) pos_b = j;
    }

    aux = ch[pos_a];
    ch[pos_a] = ch[pos_b];
    ch[pos_b] = aux;

    aux = value[a - 'a'];
    value[a - 'a'] = value[b - 'a'];
    value[b - 'a'] = aux;

    int new_value = getValue();
    if (new_value > ans) {
        for(int j = 0; j < 26; j++) str_ans[j] = ch[j];
        ans = new_value;
    }
}

int main() {

    scanf("%d %d %d", &k, &m, &n);
    scanf("\n%s", fav_letters);
    scanf("\n%s", s);

    for(int i = 0; i < 26; i++) { ch[i] = i + 'a'; value[i] = 0; }
    for(int i = 0; i < m; i++) { value[s[i]-'a']++; str_ans[s[i]-'a'] = ch[s[i]-'a']; }

    ans = getValue();

    for(int i = 0; i < n; i++) {
        char a, b;
        scanf("\n%c %c", &a, &b);
        connect(a, b);
    }

    printf("%d\n", ans);
    for(int i = 0; i < m; i++) {
        printf("%c", str_ans[s[i]-'a']);
    }
    puts("");
}
