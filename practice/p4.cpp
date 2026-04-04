#include<iostream>
using namespace std;

int pow(int x,int n){
    if(n==0){
        return 1;
    }


    int a = 1;

    if(n % 2 != 0){
        a = x * pow(x,n/2) * pow (x,n/2);
    } else{
        a = pow(x,n/2) * pow (x,n/2);
    }

    return a;
}

int main(){

    int x = 3;
    int n = 3;

    cout<<pow(x,n)<<endl;

    return 0;
}