#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> & q){
    int n = q.size();
    queue<int> u;
    for(int i=0;i<n/2;i++){
        u.push(q.front());
        q.pop();
    }

    while(!u.empty()){
        q.push(u.front());
        u.pop();

        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;

    for(int i=1;i<=10;i++){
        q.push(i);
    }

    interleave(q);

    for(int i=1;i<=10;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}