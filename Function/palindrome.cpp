#include<iostream>
using namespace std;

int palindrome(int n){
    int rev=0;
    while(n>0){
        int a = n % 10;
        rev = rev * 10 + a;

        n = n / 10;
    }
    return rev;
}

void isPalindrome(int n){
    if(palindrome(n)==n){
        cout<<"The Number is Palindrome."<<endl;
    }else{
        cout<<"The Number is not Palindrome."<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the Number:";
    cin>>n;

    isPalindrome(n);
    return 0;
}