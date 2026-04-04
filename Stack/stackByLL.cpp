#include<iostream>
#include<string>
#include<list>
using namespace std;

template<class T>
class Stack{
    list<T> ll;

public:
    void push(T val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    T top(){
        return ll.front();
    }

    bool isEmpty(){
        return ll.size()==0;
    }
};

int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    s.pop();

    cout<<s.top()<<endl;

}