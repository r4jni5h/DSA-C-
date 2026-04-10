#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices){
    int n = prices.size();
    vector<int> bestBuy(n,0);
    bestBuy[0] = INT_MAX;
    for(int i=1; i<n; i++){
        bestBuy[i] = min(prices[i-1],bestBuy[i-1]);
    }
    int maxProfit = 0;
    for(int i =0; i<n; i++){
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit,currProfit);
    }

    return maxProfit;

}

int main(){
    vector<int> prices={7,1,5,3,6,4};

    cout<<maxProfit(prices)<<endl;


    return 0;
}