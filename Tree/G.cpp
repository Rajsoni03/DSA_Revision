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

int get_diameter(Node* root){
    if (!root) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int left_max = 0;
    int right_max = 0;

    while(!q.empty()){
        pair<Node*, int> p = q.front(); q.pop();
        if (p.first->left) q.push({p.first->left, p.second-1});
        if (p.first->right) q.push({p.first->right, p.second+1});

        left_max = min(left_max, p.second);
        right_max = max(right_max, p.second);
    }
    return right_max - left_max + 1;
}

int node_sum(Node* root){
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    return node_sum(root->left) + node_sum(root->right) + root->data;
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

    cout << node_sum(root) << endl;
    return 0;
}
