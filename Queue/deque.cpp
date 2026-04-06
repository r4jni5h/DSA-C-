#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dqe;
    dqe.push_back(3);
    dqe.push_back(4);
    dqe.push_front(2);
    dqe.push_front(1);

    cout<<dqe.front()<<endl;
    cout<<dqe.back()<<endl;

    dqe.pop_front();
    dqe.pop_back();

    cout<<dqe.front()<<endl;
    cout<<dqe.back()<<endl;

    return 0;
}