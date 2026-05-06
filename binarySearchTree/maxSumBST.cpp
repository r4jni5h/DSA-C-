#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};


int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    return 0;
}