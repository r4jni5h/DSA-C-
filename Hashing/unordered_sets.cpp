#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(6);
    s.insert(7);
    s.insert(6);
    s.insert(2);

    cout<<s.size()<<endl;
    for(auto i:s){
        cout<<i<<" ";
    }
    if(s.find(6) != s.end()){
        cout<<"yes";
    }else{
        cout<<"doesn't exist";
    }
    return 0;
}