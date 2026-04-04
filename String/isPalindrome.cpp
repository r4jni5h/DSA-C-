#include<iostream>
using namespace std;

bool isPalindrome(char word[],int n){
    int st=0;
    int end=n-1;
    bool isPalin=true;
    while(st<end){
        if(word[st++]==word[end--]){
            continue;
        }else{
            isPalin=false;
        }
    }
    return isPalin;
}

int main(){
    char word[]="racecar";

    if(isPalindrome(word,strlen(word))){
        cout<<"It is Palindrome"<<endl;
    }else{
        cout<<"It is not Palindrome"<<endl;
    }
}