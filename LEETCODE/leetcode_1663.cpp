#include<iostream>
#include<string>
using namespace std;

void getSmallestString(int n, int k){
    string s(n,'a');
    k = k-n;

    int alphabet = 25;


    for(int i = n-1; i>=0; i--){
        if(k == 0){
            break;
        }
        int val = min(alphabet,k);
        s[i] = val + 'a';
        k = k - val;

    }

    cout<<s<<endl;
    cout<<k<<endl;
}

int main(){
    getSmallestString(3,27);

    return 0;
}