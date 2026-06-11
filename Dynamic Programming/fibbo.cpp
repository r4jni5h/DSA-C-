#include<iostream>
using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

// int fibDP2(int n, vector<int> f){
//     if(n == 0 || n == 1){
//         return n;
//     }
//     if(f[n] != -1){
//         return f[n];
//     }

//     return f[n] = fibDP(n-1, f) + fibDP(n-2, f);
// }

int fibTab(int n){
    vector<int> f(n, 0);
    f[0] = 0;
    f[1] = 1;

    for(int i=2; i<=n; i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}
int main(){
    int n = 13;

    cout<<fibTab(n)<<endl;
    return 0;
}