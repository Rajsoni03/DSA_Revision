#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void level_order_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* n = q.front();
        cout << n->data << endl;
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        q.pop();
    }
}

int main (){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    root->left->right->left = new Node(8);

    level_order_traversal(root);

    return 0;
}