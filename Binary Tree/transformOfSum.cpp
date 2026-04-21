#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;

}

bool rootToNodePath(Node*root, int n, vector<int>& path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    int isLeft = rootToNodePath(root->left,n,path);
    int isRight = rootToNodePath(root->right,n,path);

    if(isRight || isLeft){
        return true;
    }
    path.pop_back();

    return false;
}

int transform(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftData = transform(root->left);
    int rightData = transform(root->right);
    int currData = root->data;

    root->data = leftData + rightData ;

    if(root->left != NULL){
        root->data += root->left->data;
    }

    if(root->right != NULL){
        root->data += root->right->data;
    }


    return currData;
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root =buildTree(nodes);

    transform(root);

    cout<<root->data<<endl;



    return 0;
}