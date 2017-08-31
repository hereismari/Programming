#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    cin >> s;

    int ans = min(abs('a' - s[0]), 1 + 'z' - 'a' - abs('a' - s[0]));
    for(int i = 1; i < s.size(); i++) {
        int v = abs((s[i] - 'a') - (s[i-1] - 'a'));
        ans += min(v, 1 + 'z' - 'a' - v);
    }

    printf("%d\n", ans);
    return 0;
}
