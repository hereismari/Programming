#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std; 

struct Node {

    Node *left;
    Node *right;
    int data;
    bool initialized;
};

vector<int> in, pre, post;
int size;

void insert(Node *root, int data) {

    size++;

    if(!(root->initialized)) {
        root->initialized = true;
        root->data = data;
    }
    else {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->initialized = true;

        while(true) {
        
            if(data > root->data) {
                if(root->right != NULL && root->right->initialized)
                    root = root->right;
                else {
                    root->right = new_node;
                    break;
                }
            }
            else {
                if(root->left != NULL && root->left->initialized)
                    root = root->left;
                else {
                    root->left = new_node;
                    break;
                }
            } 
        }
    }
}

void print_vector(const vector<int> &v) {
    for(int i = 0; i < v.size()-1; i++) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[v.size()-1]);
}

bool clean_vector(vector<int> &v) {
//    if(v.size() == size) return true;
    v.clear();
    return false;
}


vector<int> prefix(Node *root, vector<int> &v) {
    v.push_back(root->data);
    
    if(root->left != NULL) {
        if(root->left->initialized) prefix(root->left, v);
    }

    if(root->right != NULL) {
        if(root->right->initialized) prefix(root->right, v);
    }

    return v;
}


vector<int> infix(Node *root, vector<int> &v) {
    if(root->left != NULL) {
        if(root->left->initialized) infix(root->left, v);
    }

    v.push_back(root->data);
    
    if(root->right != NULL) {
        if(root->right->initialized) infix(root->right, v);
    }

    return v;
}


vector<int> posfix(Node *root, vector<int> &v) {
    if(root->left != NULL && root->left->initialized) {
        posfix(root->left, v);
    }

    
    if(root->right != NULL && root->right->initialized) {
        posfix(root->right, v);
    }

    v.push_back(root->data);
    
    return v;
}



Node* search(Node *root, int x) {
    if(root == NULL || root->data == x)
        return root;
    else if(x > root->data) return search(root->right, x);
    else return search(root->left, x);
};

Node* get_min_right(Node *root) {
    while(root->left != NULL && root->left->initialized) root = root->left;
    return root;
}

void remve(Node *node) {

    if(node == NULL) return;

    Node* right_child = node->right;
    Node* left_child = node->left;

    if(right_child == NULL && left_child == NULL) {
        size--;
        node->initialized = false;
    }
    else if(right_child != NULL && left_child == NULL) {
        size--;
        node->data = right_child->data;
        node->left = right_child->left;
        node->right = right_child->right;
    }
    else if(left_child != NULL && right_child == NULL) {
        size--;
        node->data = left_child->data;
        node->left = left_child->left;
        node->right = left_child->right;
    }
    else {
        Node* right_min = get_min_right(node->right);
        node->data = right_min->data;
        remve(right_min);
    }
};


int main() {

    Node *root = new Node;
    root->initialized = false;

    string op;
    int x;
    size = 0;
    while(cin >> op) {
        if(op == "I") {
            scanf(" %d", &x);
            insert(root, x);
        }
        else if(op == "INFIXA") {
            if(clean_vector(in))
                print_vector(in);
            else 
              print_vector(infix(root, in));
        }
        else if(op == "PREFIXA") {
            if(clean_vector(pre))
                print_vector(pre);
            else 
                print_vector(prefix(root, pre));
        }
        else if(op == "POSFIXA") {
             if(clean_vector(post))
                print_vector(post);
            else 
                print_vector(posfix(root, post));
        }
        else if(op == "P") {
            scanf(" %d", &x);
            if(search(root, x) != NULL)
                printf("%d existe\n", x);
            else
                printf("%d nao existe\n", x);
        }
        else if(op == "R") {
            scanf(" %d", &x);
            remve(search(root, x));
        }
    }

	return 0; 
}
