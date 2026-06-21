#include<iostream>
#include<vector>
using namespace std;

int kanpSackRec(vector<int> wt, vector<int>val, int n, int w, vector<vector<int>> &dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        dp[n][w] = max(kanpSackRec(wt, val, n-1, w-itemWt, dp)+itemVal , kanpSackRec(wt, val, n-1, w, dp));
    }else{
        dp[n][w] = kanpSackRec(wt, val, n-1, w, dp);
    }
    return dp[n][w];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    cout<<kanpSackRec(wt, val, n, w, dp)<<endl;

    return 0;
}