#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
public:
    Node* head;
    Node* tail;
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
    //Print List
    void print_list(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void removeCycle(Node* head){
    //detect_cycle
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){ 
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            cout<<"Cycle Exist \n";
            isCycle = true;
            break;
        }
    }
    if(!isCycle){
        cout<<"Cycle Doesn't Exist \n";
        return;
    }
    slow = head;
    if(slow==fast){
        while(fast->next!=slow){
            fast = fast->next;
        }
        fast->next=NULL;
    }else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }

}

int main(){
    List ll;

    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.print_list();

    ll.tail->next = ll.head;

    removeCycle(ll.head);

    ll.print_list();
    
    removeCycle(ll.head);

    
    return 0;
}