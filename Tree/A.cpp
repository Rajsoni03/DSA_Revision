#include <iostream> 
#include <stack>
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

// 4 2 8 5 1 6 3 7
void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

// 4 2 8 5 1 6 3 7
void inorder_iter(Node* root){
    stack<Node*> s;
    while(root || !s.empty()){
        while(root){
            s.push(root); // backup
            root = root->left;
        }
        cout << s.top()->data << endl;
        root = s.top()->right;
        s.pop();
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

    inorder_iter(root);

    return 0;
}