#include<iostream>
using namespace std;

int binSearch(int arr[],int n, int key){
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid]==key){
            return mid;
        }else if (key > arr[mid]){
            start = mid + 1;
        }else if(key<arr[mid]){
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[]={2,4,6,8,10,12,14};
    int n=sizeof(arr)/sizeof(int);

    cout<<binSearch(arr,n,4)<<endl;

}