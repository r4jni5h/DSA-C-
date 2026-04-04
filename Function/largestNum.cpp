#include<iostream>
using namespace std;

void largestNum(int a,int b,int c){
    if(a>b&&a>c){
        cout<<"The Largest Number is A."<<endl;
    }else if(b>c){
        cout<<"The Largest Number is B."<<endl;
    }else{
        cout<<"The Largest Number is C."<<endl;
    }
}

int main(){

    int a,b,c;

    cout<<"Enter the A :";
    cin>>a;
    cout<<"Enter the B :";
    cin>>b;
    cout<<"Enter the C :";
    cin>>c;

    largestNum(a,b,c);
    

}