#include <bits/stdc++.h>
#define MAX 20000000
#include <string>

using namespace std;
map<string,int> visited;

void dfs(string value, int n){
    if(visited[value] == 0)
    {
        cout << value;
        visited[value] = 1;
        for(int i = 0; i <= 9; i++){
            string new_value = value + (char)('0'+i);
            int begin = new_value.size()-n >= 0 ? new_value.size()-n:0;
            int size = n <= new_value.size() ? n : new_value.size();
            dfs(new_value.substr(begin),n);
        }
    }
}

int main() {

    int n;
    while(scanf("%d",&n) != EOF){
        visited.clear();
        dfs("",n);
        printf("\n");
    }
    return 0;
}
