#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printll(list <int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    ll.push_front(0);

    printll(ll);

    cout<<ll.size()<<endl;

    cout<<"Head :"<<ll.front()<<endl;
    cout<<"Tail :"<<ll.back()<<endl;

    return 0;
}