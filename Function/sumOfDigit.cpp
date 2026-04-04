#include<iostream>
using namespace std;

int sumOfDigit(int n){
    int res=0;
    while(n>0){
        res+= n % 10;
        n=n/10;
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter the Number:";
    cin>>n;

    cout<<sumOfDigit(n)<<endl;
}