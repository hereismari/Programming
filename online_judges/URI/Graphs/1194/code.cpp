#include <bits/stdc++.h>

using namespace std;

#define INVALID_INDEX -1

struct tree {
    char data;
    tree *left;
    tree *right;
};

int n;

void postfix(tree* root, string &s) {
    if(root->left != NULL) postfix(root->left, s);
    if(root->right != NULL) postfix(root->right, s);
    s += root->data;
}

tree* solve(string prefix, string infix, int b, int e, int pos=0) {

    tree* root = new tree;
    root->data = prefix[pos];
    int l = 0, r = 0, m = INVALID_INDEX;
    for(int i = b; i <= e; i++) {
        if(infix[i] == prefix[pos]) m = i;
        else if(m == INVALID_INDEX) l++;
        else r++;
    }

	if(m == INVALID_INDEX) return NULL;

    if(l > 0) {
        root->left = solve(prefix, infix, b, m-1, pos+1);
    }
    else {
        root->left = NULL;
    }
	
    if(r > 0) {
        root->right = solve(prefix, infix, m+1, e, m+1);
    }
    else {
        root->right = NULL;
    }


/*	if(root->left != NULL)
    	printf("%c left child: %c\n", root->data, root->left->data);
	
	if(root->right != NULL)
    	printf("%c right child: %c\n", root->data, root->right->data);
*/	

    return root;
}


string solve(string prefix, string infix, int size) {
	tree *root = solve(prefix, infix, 0, size-1);
    string res = "";
    postfix(root, res);
	return res;
}
int main() {

    int t;
    string prefix, infix;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        cin >> prefix >> infix;
        cout << solve(prefix, infix, n) << endl;
    }

    return 0;
}

