#include<iostream>
using namespace std;

void MaxSubarraySum1(int *arr,int n){
    int maxSum = INT_MIN;
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            int currSum=0;
            for(int i=start;i<=end;i++){
                currSum += arr[i];
            }
            cout<<currSum<<", ";  
            maxSum = max(maxSum,currSum);       
        }
        cout<<endl;
    }
    cout<<"Maximum Sum of Subarray :"<<maxSum;
}

void MaxSubarraySum2(int arr[],int n){
    int maxSum = INT_MIN;
    for(int start=0;start<n;start++){
        int currSum=0;
        for(int end=start;end<n;end++){
            currSum += arr[end];
        }
        maxSum = max(currSum,maxSum);
    }
    cout<<"Maximum Sum of Subarray : "<<maxSum<<endl;
}

//kadan's Algorith
 void MaxSubarraySum3(int arr[],int n){
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        maxSum=max(maxSum,currSum);
        if(currSum < 0){
            currSum=0;
        }
    }
    cout<<"Maximum Sum of Subarray :"<<maxSum<<endl;
 }


int main(){

    int arr[]={2,-3,6,-5,4,2};
    int n=sizeof(arr)/sizeof(int);

    MaxSubarraySum3(arr ,n);
    return 0;
}