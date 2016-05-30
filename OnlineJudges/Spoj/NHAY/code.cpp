#include <bits/stdc++.h>

using namespace std;

void preprocess(string p, int v[]){

    v[0] = 0; 
    v[1] = 0;  

    int cur = 0;
    int length = p.size();

    for(int j = 2; j < length; j++){
        
		while(cur != 0 && p[cur] != p[j-1])
            cur = v[cur];
 
        if(p[cur] == p[j-1])
            cur = cur + 1;

        v[j] = cur;    
	}
}
 
void kmp(string pattern, string text, int v[]){

    preprocess(pattern, v);
    int cur = 0; 
    int length_text = text.size();
    int length_pattern = pattern.size();
    int flag = 0, j = 0;
    while(j < length_text){
       
		 while(cur > 0 && pattern[cur] != text[j])
            cur = v[cur];
 
        if(pattern[cur] == text[j]){
            cur++;
            if(cur == length_pattern){
                cout << j - length_pattern + 1<< endl;
                cur--;
                cur = v[cur];
                flag = 1;
                j--;
            }
        }
        j++;
    }
}
 
int main(){

    int length;
    scanf("%d", &length);
    while(1){
        int v[length+1];
		string text, pattern;
        cin >> pattern >> text;
        kmp(pattern, text,v);
        if(scanf("%d",&length) == 1) cout << endl;
        else break;
    }

    return 0;
}

