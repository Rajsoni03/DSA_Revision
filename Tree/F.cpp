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


void helper(Node* root, int column, int& left, int& right){
    if (!root) return;

    helper(root->left, column-1, left, right);
    helper(root->right, column+1, left, right);

    left = min(left, column);
    right = max(right, column);
}


int get_dia_recursion(Node* root){
    int left = 0;
    int right = 0;
    helper(root, 0, left, right);

    if (!root) return 0;
    else return right - left + 1;
}

int main (){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    
    // root->left->right->left = new Node(8);
    // root->right->right->left = new Node(9);

    cout << get_dia_recursion(root) << endl;

    return 0;
}
