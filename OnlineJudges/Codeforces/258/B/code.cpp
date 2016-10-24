#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define FLAG -1

int begin, end;

bool solve(vector<int> v) {

    int n = v.size();
    begin = end = 0;

    for(int i = 0; i < n-1; i++) {
        if(v[i] > v[i+1]) {
            begin = i;
            break;
        }
    }

    for(int i = n-1; i >= 1; i--) {
        if(v[i] < v[i-1]) {
            end = i;
            break;
        }
    }

    reverse(v.begin() + begin, v.begin() + end + 1);

    for(int i = 0; i < n-1; i++) {
       if(v[i] > v[i+1]) return false; 
    }

    return true;
}

int main() {

    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    if(solve(v)) {
        printf("yes\n");
        printf("%d %d\n", begin+1, end+1);
    }
    else {
        printf("no\n");
    }

    return 0;
}
