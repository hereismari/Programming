#include <bits/stdc++.h> 

#define MAX 1001001 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

/*
 * C++ Program to Implement Knuth–Morris–Pratt Algorithm (KMP)
 */
#include <iostream>
#include <cstring>
using namespace std;

void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i <= m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
void kmp(string pattern, string target ,int f[]) {

    int m = pattern.length();
    int n = target.length();
    preKMP(pattern, f);     
    int i = 0;
    int j = 0;        
    while (i < n)
    {
        if (j == -1)
        {
            i++;
            j = 0;
        }
        else if (target[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m) { printf("%d\n",i-m); j = f[j];}
        }
        else
            j = f[j];
    }
}
 
int main(){

    int length;
    scanf("%d", &length);
    while(1){
        int r[length+1];
		string text, pattern;
        cin >> pattern >> text;
        kmp(pattern, text, r);
        if(scanf("%d",&length) == 1) cout << endl;
        else break;
    }

    return 0;
}
