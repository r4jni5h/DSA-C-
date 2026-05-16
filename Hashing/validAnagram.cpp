#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool validAnagram(string s, string t){
    unordered_map<char,int>freq;

    for(int i=0; i<s.size(); i++){
        freq[s[i]]++;
    }
    for(int i=0; i<t.size(); i++){
        if(freq.count(t[i])){
            freq[t[i]]--;
            if(freq[t[i]]==0){
                freq.erase(t[i]);
            }
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";

    cout<<validAnagram(s,t);
    return 0;
}