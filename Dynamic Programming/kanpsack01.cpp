#include<iostream>
#include<vector>
using namespace std;

int kanpSackRec(vector<int> wt, vector<int> val, int n, int w){
    if(n==0 || w==0){
        return 0;
    }
    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    if(itemWt <= w){
        //include
        int ans1 = kanpSackRec(wt, val, n-1, w-itemWt) + itemVal;
        //exclude
        int ans2 = kanpSackRec(wt, val, n-1, w);

        return max(ans1, ans2);
    }else{
        //exclude
        return kanpSackRec(wt, val, n-1, w);
    }
}


int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;

    cout<<kanpSackRec(wt, val, n, w)<<endl;

    return 0;
}