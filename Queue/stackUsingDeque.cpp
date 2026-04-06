#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> d;
public:
    void push(int val){
        d.push_back(val);
    }
    void pop(){
        d.pop_back();
    }
    int top(){
        return d.back();
    }
    bool empty(){
        return d.empty();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.top()<<endl;

    return 0;
}