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

Node* insert(Node* root, int val){
    if(root==NULL){
        return root = new Node(val);
    }

    if(val<root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }

    return root;
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}

bool validateBST(Node* root, Node* min, Node* max){
    if(root==NULL){
        return true;
    }

    if( min != NULL && root->data <= min->data){
        return false;
    }

    if( max != NULL && root->data >= max->data){
        return false;
    }

    return validateBST(root->left,min,root)
        && validateBST(root->right,root,max);


}


int main(){
    int arr[] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr)/sizeof(int);

    Node* root = buildBST(arr,n);
    // root->data = 15;

    cout<< validateBST(root,NULL,NULL) <<endl;


    return 0;
}