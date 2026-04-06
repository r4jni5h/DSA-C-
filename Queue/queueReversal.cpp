#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);

    return 0;
}