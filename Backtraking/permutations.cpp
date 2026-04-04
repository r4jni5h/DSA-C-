#include<iostream>
#include<string>
using namespace std;

void permutation(string str,string ans){
    int n = str.size();
    if(n==0){
        cout<<ans<<endl;
    }
    for(int i=0;i<n;i++){
        char ch = str[i];
        string nextString = str.substr(0,i)+str.substr(i+1,n-i-1);
        permutation(nextString,ans+ch);
    }
}

int main(){
    string str="abc";
    string ans="";

    permutation(str,ans);
}
