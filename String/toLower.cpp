#include<iostream>
using namespace std;

int main(){
    char word[]= "RAJNISH YADAV" ;

    for(int i=0;i<strlen(word);i++){
        char ch = word[i];
        if(ch>='A' && ch<='Z'){
            word[i]= word[i]-'A'+'a';
        } 
    }
    cout<<word<<endl;
    
}