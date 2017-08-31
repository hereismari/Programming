#include <bits/stdc++.h>

#define MAX 15
#define ALPHABET_SIZE 30

using namespace std;

struct node {
	bool is_leaf;
	int size;
	char value;
	node * children[ALPHABET_SIZE];
};

node * getNode() {
    node * result = (node*)malloc(sizeof(node));
    result->size = 0;
    result->is_leaf = false;
    result->value = '*';
    for(int i = 0; i < ALPHABET_SIZE; i++) result->children[i] = NULL;
    return result;
}


node * trie;

void ins(char *key) {

    int length = strlen(key);
    int index;
 
    node * crawl = trie;
    for (int level = 0; level < length; level++) {
    	crawl->size = crawl->size + 1;
        index = key[level] - '0';
        if (!crawl->children[index]) crawl->children[index] = getNode();
        crawl->children[index]->value = key[level];
        crawl = crawl->children[index];
    }
 
    crawl->is_leaf = true;
}


char aux[MAX];
int n;
bool ans;


//DFS
void dfs(node *root) {

	if(root->is_leaf && root->size > 0) ans = false;
	else {
		for(int i = 0; i < ALPHABET_SIZE; i++)
			if(root->children[i])
				dfs(root->children[i]);
	}
}


int main(){

	int t;
	scanf("%d", &t);

	while(t--) {
		
		ans = true;
		trie = getNode();
		
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("\n%s", aux);
    		ins(aux);
		}
		
	 	dfs(trie);
	    printf("%s\n", ans ? "YES" : "NO");
	}

    return 0;
}
