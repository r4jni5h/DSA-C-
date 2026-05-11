#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class Hashtable{
    int totSize;
    int currSize;
    Node** table;
    int HashFunction(string key){
        int idx = 0;
        for(int i=0; i<key.size(); i++){
            idx = (idx + (key[i] * key[i]) % totSize) % totSize;
        }
        return idx;
    }
    void rehash(){
        Node** oldTable = table;
        int oldTabSize = totSize;
        currSize = 0; 

        totSize = 2*totSize;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i]=NULL;
        }

        //copy old Values
        for(int i=0; i<oldTabSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key,temp->val);
                temp =temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }
public:
    Hashtable(int size=5){
        totSize = size;
        currSize =0;
        table = new Node*[totSize];

        for(int i=0; i<totSize; i++){
            table[i]=NULL;
        }
    }

    void insert(string key, int val){
        int idx = HashFunction(key);

        Node* newNode = new Node(key,val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totSize;
        if(lambda>1){
            rehash();
        }
    }

    bool exist(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
    int search(string key){
        int idx = HashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key)
                return temp->val;
            temp = temp->next;
        }
        return -1;

    }
    void print(){
        for(int i=0; i<totSize; i++){
            cout<<i<<"->";
            Node* temp = table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->val<<")"<<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
        
    void remove(string key){
        int idx = HashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                return;
                currSize--;
            }
            prev = temp;
            temp=temp->next;
        }
    }
};

int main(){
    Hashtable ht;
    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    ht.print();
    ht.remove("China");
    cout<<"---------"<<endl;
    ht.print();
    ht.remove("UK");
    cout<<"---------"<<endl;
    ht.print();
    return 0;
}