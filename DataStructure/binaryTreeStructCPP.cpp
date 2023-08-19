#include <iostream>

using namespace std;


class TreeNode {
public: 
    char element;
    TreeNode * left;
    TreeNode * right;

    TreeNode(char element) {
        this->element = element;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TreeNode* node) {
    if(node == NULL) return;

    cout << node->element << endl;
    preOrder(node->left);
    preOrder(node->right);
}


int main() {
    TreeNode* a = new TreeNode('A');
    TreeNode* b = new TreeNode('B');
    TreeNode* c = new TreeNode('C');
    TreeNode* d = new TreeNode('D');
    TreeNode* e = new TreeNode('E');
 
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = c->right = NULL;
    d->left = d->right = NULL;
    e->left = e->right = NULL;

    preOrder(a);
}