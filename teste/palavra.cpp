#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    char s[1100];
    while (scanf("%s", s) != EOF) {
        s[0] = toupper(s[0]);
        printf("%s\n", s);
    }
    return 0;
}
