#include<iostream>
#include<cstring>
using namespace std;

void revStr(char word[], int n){
    int st = 0;
    int end = n - 1;

    while(st <= end){
        swap(word[st], word[end]);
        st++;
        end--;  
    }
}

int main(){
    
    char str[] = "code";
    int n = strlen(str);

    revStr(str, n);
    cout << str << endl;
    
}