#include<iostream>
#include<string>
using namespace std;

int mirrorDistance(int n) {
    int original = n;
    string str ;
    while(n != 0){
        char dig = '0' + (n % 10);
        str += dig;
        n /= 10;
    }

    int reversed = stoi(str);

    return abs(original-reversed);
    
}

int main(){
    int n  = 25;

    cout<<mirrorDistance(n);

    return 0;
}