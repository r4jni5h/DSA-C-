#include<iostream>
#include<vector>
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

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void getInOrderT(Node* root,vector<int> & arr){
    if(root==NULL){
        return;
    }
    getInOrderT(root->left,arr);
    arr.push_back(root->data);
    getInOrderT(root->right,arr);
}

Node* bstfromSortedArr(vector<int> arr,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid = st+end;
    Node* curr = new Node(arr[mid]);

    curr->left = bstfromSortedArr(arr,st,mid-1);
    curr->right = bstfromSortedArr(arr,mid+1,end);

    return curr;   
}

Node* bstToBalbst(Node* root){
    vector<int>arr;
    getInOrderT(root,arr);

    return bstfromSortedArr(arr,0,arr.size()-1);
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = bstToBalbst(root);

    preOrder(root);


    return 0;
}