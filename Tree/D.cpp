#include <iostream> 
#include <deque>
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

void zig_zag(Node* root){
    deque<Node*> q;
    q.push_back(root);
    int count = 0;
    int level = 0;
    while(!q.empty()){
        count = q.size();
        for (int i = 0; i < count; i++){
            if (level%2==0){
                Node* n = q.front(); q.pop_front();
                cout << n->data << " ";
                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }
            else{
                Node* n = q.back(); q.pop_back();
                cout << n->data << " ";
                if (n->right) q.push_front(n->right);
                if (n->left) q.push_front(n->left);
            }
        }
        cout << endl;
        level++;
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
    root->right->right->left = new Node(9);

    zig_zag(root);

    return 0;
}