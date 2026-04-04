#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack{
    vector<T> vec;

public:

    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    T top(){
        int sizeIdx = vec.size()-1;
        return vec[sizeIdx];
    }

    bool isEmpty(){
        return vec.size()==0;
    }

};

int main(){
    Stack<string> s;

    s.push("is Rajnish");
    s.push("Name");
    s.push("My");


    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}