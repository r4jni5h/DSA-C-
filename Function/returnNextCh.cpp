#include<iostream>
using namespace std;

char nextCharacter(char ch){
    if(ch=='z'){
        return 'a';
    }else{
        return ch +1;
    }
}

int main(){
    char ch;
    cout<<"Enter the Character:";
    cin>>ch;

    cout<<nextCharacter(ch)<<endl;

    return 0;
}