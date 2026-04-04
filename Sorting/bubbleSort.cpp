#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            break;
        }
    }
    printArray(arr,n);
}


int main(){
    int arr[]={12,43,12,3,21,21,2,3,4,2,4,32,42,7,8,9,05,43,22};
    int n=sizeof(arr)/sizeof(int);

    bubbleSort(arr,n);
}