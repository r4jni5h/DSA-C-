#include<iostream>
#include<string>
using namespace std;

void substring(string str,string subset){

    if(str.size()==0){
        cout<<subset<<endl;
        return;
    }

    char ch = str[0];
    substring(str.substr(1,str.length()-1),subset+ch);

    substring(str.substr(1,str.length()-1),subset);

}


int main(){
    string str = "abc";
    string subset ="";

    substring(str,subset);

}