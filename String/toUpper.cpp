#include<iostream>
using namespace std;

int main(){
    char word[]= "RAJNISH YADAV" ;

    for(int i=0;i<strlen(word);i++){
        char ch = word[i];
        if(ch>='a' && ch<='z'){
            word[i]= word[i]-'a'+'A';
        } 
    }
    cout<<word<<endl;
    
}