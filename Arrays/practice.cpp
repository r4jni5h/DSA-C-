#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void reverse(int arr[],int n){
        int st=0;
        int end=n-1;
        while(st<end){
            swap(arr[st++],arr[end--]);
        }
    printArray(arr, n);
}

int main(){
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(int);

    reverse(arr,n);

    return 0;


}