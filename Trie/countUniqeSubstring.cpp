#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]] = new Node;
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }
    int countHelper(Node* root){
        int ans = 1;
        for(pair<char, Node*> child:root->children){
            ans += countHelper(child.second);
        }
        return ans;
    }

    int countNode(){
        return countHelper(root);
    }


};

int countUniqueSubstring(string s){
    Trie trie;
    for(int i=0; i<s.size(); i++){
        trie.insert(s.substr(i));
    }

    return trie.countNode();
}



int main(){
    string s = "abc";

    cout<<countUniqueSubstring(s);

    return 0;
}