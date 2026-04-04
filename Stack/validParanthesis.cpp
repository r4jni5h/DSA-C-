#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool validParathesis(string str){
    stack <char> c ;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(ch=='(' || ch=='{' || ch=='['){
            c.push(ch);
        }else{
            if(c.empty()){
                return false;
            }
            char top = c.top();
            if(top == '(' && ch == ')' ||
               top == '{' && ch == '}' ||
               top == '[' && ch == ']'){
                c.pop();
            }else{
                return false;
            }
        }
    }
    return c.empty();
}

int main(){
    string s1 = "{{([])}}";
    string s2 = "{{[]}}";

    cout<<validParathesis(s1)<<endl;
    cout<<validParathesis(s2)<<endl;
    return 0;
}