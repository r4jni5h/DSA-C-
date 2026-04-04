#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }
    //Push Front
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    //push_back
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next= newNode;
            tail=newNode;
        }
    }
    //printList
    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
    //Insert
    void Insert(int val,int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    //pop_front
    void pop_front(){
        Node* temp = head;
        head= temp->next;
        temp = NULL;
        delete temp;
    }
    //push_back
    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail=temp;
    }
    //Search Iterative
    int searchItr(int key){
        Node* temp = head;
        int idx=0;
        while(temp != NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    //Reverse Linked List
    void reverseLL(){
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }    

    //remove Nth
    int getSize(){
        Node* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }

    void removeNth(int n){
        int size = getSize();
        Node* prev = head;
        for(int i=1;i<(size-n);i++){
            prev = prev->next;
        }

        prev->next = prev->next->next;
    }

};

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);

    ll.printList();

    ll.removeNth(3);
    ll.printList();

    return 0;
}
