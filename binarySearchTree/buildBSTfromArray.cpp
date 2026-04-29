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

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

bool searchBST(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key < root->data){
        return searchBST(root->left, key);
    }else{
        return searchBST(root->right, key);
    }
}

Node* IS(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = deleteNode(root->left,val);
    }else if(val > root->data){
        root->right = deleteNode(root->right,val);
    }else{
        // case 1:
        if(root->left == NULL && root->right){
            delete root;
            return NULL;
        }

        // case 2:
        if(root->left ==NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left ;
        }

        // case 3:
        Node* iS = IS(root->right);

        root->data = iS->data ;
        root->right = deleteNode(root->right,iS->data);
        return root;
    }
    return root;
}

int main(){
    int arr[]={5,1,3,4,2,7};
    int arr2[] = {8,5,3,1,4,6,10,11,14};
    int n = sizeof(arr2)/sizeof(int);

    Node* root = buildBST(arr2,n);

    inOrderTraversal(root);
    cout<<endl;

    deleteNode(root,5);

    inOrderTraversal(root);
    cout<<endl;

    return 0;
}