#include<iostream>
#include<stack>
using namespace std;

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

int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s,4);

    pushAtBottom(s,5);

    pushAtBottom(s,6);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
