#include<iostream>
using namespace std;

void printArr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    int start =0;
    int end = n-1;
    while(start<end){
        swap(arr[start++],arr[end--]);
    }

    printArr(arr,n);
    return 0;
}