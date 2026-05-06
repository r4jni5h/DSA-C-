#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<string, vector<string>, greater<string>> pq;

    pq.push("Rajnish");
    pq.push("Aman");
    pq.push("Karan");
    pq.push("Venktesh");
    pq.push("Lokesh");
    pq.push("Zeel");

    while(!pq.empty()){
        cout<<pq.top()<<" "<<endl;
        pq.pop();
    }

    return 0;
}