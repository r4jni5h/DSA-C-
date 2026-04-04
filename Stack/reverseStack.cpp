#include<iostream>
#include<stack>
using namespace std;

void printStack(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void pushAtBottom(stack<int>& s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int lastVal = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(lastVal);
}

void reverseStack(stack<int> & s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,temp);
}

int main(){
    stack<int> s;
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    printStack(s);

    reverseStack(s);

    printStack(s);

    return 0;
}