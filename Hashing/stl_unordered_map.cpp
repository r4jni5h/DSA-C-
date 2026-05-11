#include<iostream>
#include<unordered_map>
using namespace std;

void print_up(unordered_map<string, int>& m){
    for(pair<string,int> country : m){
        cout<<country.first<<","<<country.second<<endl;
    }
}

int main(){
    unordered_map<string, int> m;
    m["India"]=150;
    m["China"]=150;
    m["Nepal"]=40;
    m["US"]=50;
    m["UK"]=30;

    print_up(m);
    cout<<"_________"<<endl;

    m.erase("US");


    print_up(m);

    return 0;
}