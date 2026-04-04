#include<iostream>
#include<string>

using namespace std;

bool validAnagram(string s, string t){
    int m = s.length();
    int n = t.length();
    int count[26]={0};

    if(m != n){
        return false;
    }
    for(int i=0;i<m;i++){
        count[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(count[t[i]-'a']==0){
            return false;
        }
        count[t[i]-'a']--;
    }
    return true;

}

int main(){
    string str1= "anagram";
    string str2= "nagaram";

    cout<<validAnagram(str1,str2)<<endl;
}