#include<iostream>
#include<vector>
using namespace std;

vector<int> threeCommon(vector<int> arr,vector<int> arr2,vector<int> arr3){
    int n = arr.size();
    int m = arr2.size();
    int l = arr3.size();
    for(int i=0; i<n; i++){
        int st1 = 0;
        int end1 = arr2.size()-1;
        int ans = 0;
        while(st1>end1){
            int mid1 = (st1+end1)/2;
            if(arr[i]==arr2[mid1]){
                ans = arr2[mid1];
            }
            if()
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    vector<int> arr = {1,3,4,6};
    vector<int> arr = {1,5,6};



    return 0;
}