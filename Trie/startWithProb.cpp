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
    bool search(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }
    bool validPrefix(Trie& trie, string prefix){
        Node* temp = root;
        for(int i=0; i<prefix.size(); i++){
            if(temp->children.count(prefix[i])){
                temp = temp->children[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }

};

bool startWith(vector<string> word, string prefix){
    Trie trie;
    for(int i=0; i<word.size(); i++){
        trie.insert(word[i]);
    }

    return trie.validPrefix(trie, prefix);
}

int main(){
    vector<string> word = {"apple", "app", "mango", "man", "women"};

    cout<<startWith(word, "moon")<<endl;

    return 0;
}