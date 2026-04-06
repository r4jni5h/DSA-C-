#include<iostream>
#include<string>
using namespace std;

void firstNonRepeat(string str){
    queue<char> q;
    int freq[26]={0};
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front()-'a']>1){
            q.pop();
        }

        if(q.empty()){
            cout<<"-1"<<endl;
        }else{
            cout<<q.front()<<endl;
        }
    }
}

int main(){

    string str = "aabccxb";

    firstNonRepeat(str);
    return 0;
}