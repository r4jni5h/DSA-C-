#include<iostream>
#include<deque>
using namespace std;

class Queue{
public:
    deque<int> d;

    void push(int val){
        d.push_back(val);
    }
    void pop(){
        d.pop_front();
    }
    int front(){
        return d.front();
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();

    return 0;
}