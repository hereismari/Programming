#include <bits/stdc++.h>

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 300 
#define INF 1000000000

int n, m, x, y, k;
char mat[MAX][MAX];
int sums[MAX][MAX];
char c;

string s, ans;


char verify(int a1, int b1, int a2, int b2) {

    char res = mat[a1][b1];
    for(int i = a1; i < a2; i++)
        for(int j = b1; j < b2; j++)
            if(mat[i][j] != res) return '2';
   
    return res;
} 
/*
char verify(int top, int left, int bottom, int right) {

    int sum = sums[bottom-1][right-1];
    
    if (top && left)
        sum += sums[top - 1][left - 1] - sums[top - 1][right-1] - sums[bottom-1][left - 1];
    else if (top) sum -= sums[top - 1][right-1];
    else if (left) sum -= sums[bottom-1][left - 1];
    
    if (!sum) return '0'; // all zeros
    else if (sum == (bottom - top) * (right - left)) return '1'; // all ones
    else return '2';
}
*/
void solve1(int a1, int b1, int a2, int b2) {

    if(a1 >= a2 || b1 >= b2) return;

    if(a1 == a2-1 && b1 == b2-1) { 
        ans += mat[a1][b1];
        return;
    }

    char v = verify(a1, b1, a2, b2);

    if(v != '2') ans += v;
    else {

        ans += 'D';
        
        int d1 = (a2 - a1),  d2 = (b2 - b1);

        // top left
        solve1(a1, b1, a1 + d1/2 + d1 % 2, b1 + d2/2 + d2 % 2);
        // top right
        solve1(a1, b1 + d2/2 + d2 % 2, a1 + d1/2 + d1 % 2, b2);
        // bottom left
        solve1(a1 + d1/2 + d1 % 2, b1, a2, b1 + d2/2 + d2 % 2);
        // bottom right
        solve1(a1 + d1/2 + d1 % 2, b1 + d2/2 + d2 % 2, a2, b2);
    }
}

void solve2(int a1, int b1, int a2, int b2) {

    if(a2 > a1 && b2 > b1) k++;
    else return;
    
    if(s[k-1] == '1' || s[k-1] == '0') {
        for(int i = a1; i < a2;  i++)
            for(int j = b1; j < b2; j++)
                mat[i][j] = s[k-1];
    }

    else { 
     
        int d1 = (a2 - a1),  d2 = (b2 - b1);

        // top left
        solve2(a1, b1, a1 + d1/2 + d1 % 2, b1 + d2/2 + d2 % 2);
        // top right
        solve2(a1, b1 + d2/2 + d2 % 2, a1 + d1/2 + d1 % 2, b2);
        // bottom left
        solve2(a1 + d1/2 + d1 % 2, b1, a2, b1 + d2/2 + d2 % 2);
        // bottom right
        solve2(a1 + d1/2 + d1 % 2, b1 + d2/2 + d2 % 2, a2, b2);
    }
}

int main() {
 
    while(cin >> c) {
        
        if(c == '#') break;

        cin >> n >> m;
        cin.ignore();

        cout << (c == 'B'? "D" : "B") 
             << right << setw(4) << n 
             << right << setw(4) << m 
             << endl;

        cin >> s;

        ans = "";
        if(c == 'B') {
        
            int count = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++) {
                    
                    mat[i][j] = s[count++];
                    sums[i][j] = mat[i][j] == '1';

                    if(i && j) 
                        sums[i][j] += sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
                    else if(i)
                        sums[i][j] += sums[i-1][j];
                    else if(j) sums[i][j] += sums[i][j-1];
                
                }

/*
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++)
                    printf("%d ", sums[i][j]);
                puts("");
            }
*/
            solve1(0, 0, n, m);
        }
        
        else {
            
            k = 0;
            solve2(0, 0, n, m);
            
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    ans += mat[i][j];
        }
        
        cout << ans << endl;
    }

	return 0; 
}
