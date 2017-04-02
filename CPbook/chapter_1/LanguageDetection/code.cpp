#include <bits/stdc++.h>

using namespace std;

int main() {

    map<string, string> m;

    m["HELLO"] = "ENGLISH";
    m["HOLA"] = "SPANISH";
    m["HALLO"] = "GERMAN";
    m["BONJOUR"] = "FRENCH";
    m["CIAO"] = "ITALIAN";
    m["ZDRAVSTVUJTE"] = "RUSSIAN";

    string s;
    int c = 1;
    while(cin >> s) {
        if(s == "#") break;
        printf("Case %d: ", c++);
        if(m.find(s) != m.end()) {
            cout << m[s] << endl;
        }
        else {
            printf("UNKNOWN\n");
        }
    }

    return 0;
}

