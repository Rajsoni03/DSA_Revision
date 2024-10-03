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

void prinr_level(Node* root, int level_index){
    queue<Node*> q;
    q.push(root);
    int count = 0;
    int level = 0;
    while(!q.empty()){
        count = q.size();
        for (int i = 0; i < count; i++){
            Node* n = q.front(); q.pop();
            if (level == level_index){
                cout << n->data << endl;
            }
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        level++;
    }
}

int main (int n, char* args[]){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    root->left->right->left = new Node(8);

    int level_index = stoi(args[1]);
    prinr_level(root, level_index);

    return 0;
}