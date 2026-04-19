#include<iostream>
#include<vector>
#include<map>
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

void kthLevelPrint(Node* root,int k){
    queue<Node*> q;

    q.push(root);
    int level=1;

    while(!q.empty()){
        int size = q.size();
        if(level==k){
            for(int i=0; i<size; i++){
                cout<<q.front()->data<<" ";
                q.pop();
            }
            cout<<endl;
            return;
        }
        for(int i=0; i<size; i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        level++;
    }

}

void kthLevelPrint2(Node* root,int k,int level){
    if (root == NULL) return;

    if(level==k){
        cout<<root->data<<" "<<endl;
        return ;
    }
    kthLevelPrint2(root->left,k,level+1);
    kthLevelPrint2(root->right,k,level+1);

}




int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root =buildTree(nodes);

    kthLevelPrint2(root, 3,1);

    
    return 0;
}