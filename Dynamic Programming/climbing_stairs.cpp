#include<iostream>
using namespace std;

int climbingStair(int n, vector<int>& dp){
    if(n == 0|| n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = climbingStair(n-1, dp) + climbingStair(n-2, dp);
    return dp[n];
}

int main(){
    int n = 7;
    vector<int> dp(n+1, -1);
    cout<<climbingStair(n, dp)<<endl;
    return 0;
}