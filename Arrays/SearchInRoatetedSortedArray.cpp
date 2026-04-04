#include<iostream>
using namespace std;

int search(int arr[],int n,int tar){

    int st = 0;
    int en = n-1;

    while(st<=en){
        int mid = (st + en)/2;

        if(arr[mid]==tar){
            return mid;
        }
        if(arr[st]<arr[mid]){
            if(arr[st]<=tar && tar<=arr[mid]){
                en=mid-1;
            }else{
                st=mid+1;
            }

        }else{
            if(arr[mid]<=tar && tar<= arr[en]){
                st = mid+1;
            }else{
                en = mid-1;
            }

        }

    }
    return -1;

}

int main(){

    int arr[]={4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);
    int tar = 0;

    cout<< search(arr, n, tar)<<endl;
    return 0;
}